#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX (1<<30)
#define MAPSIZE 20

const char directChar[][6] = {"nesw","NESW"};
const int directI[] = {-1,0,1,0};
const int directJ[] = {0,1,0,-1};
bool pushAppear[20][20][4];
char map[MAPSIZE][MAPSIZE+4];
int r,c;
int directions[20][20];

class Position{
public:
	int i,j;
}start,box,target;

class Cost{
public:
	int pushCost;
	int walkCost;
	bool operator < (const Cost &b) const{
		if(pushCost != b.pushCost){
			return pushCost < b.pushCost;
		}
		else{
			return walkCost < b.walkCost;
		}
	}
}dp[MAPSIZE][MAPSIZE][MAPSIZE][MAPSIZE];

void initialize(){
	for(int i=0;i<r;++i){
		scanf("%s",map[i]);
		for(int j=0;j<c;++j){
			if(map[i][j] == 'T'){
				target.i = i, target.j = j;
			}
			else if(map[i][j] == 'B'){
				box.i = i, box.j = j;
			}
			else if(map[i][j] == 'S'){
				start.i = i, start.j = j;
			}
		}
	}
	memset(pushAppear,0,sizeof pushAppear);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			for(int p=0;p<r;++p){
				for(int q=0;q<c;++q){
					dp[i][j][p][q].pushCost = MAX;
					dp[i][j][p][q].walkCost = MAX;
				}
			}
			dp[i][j][target.i][target.j].pushCost = 0;
			dp[i][j][target.i][target.j].walkCost = 0;
		}
	}
}

bool validPosition(const int ni,const int nj){
//	printf("valid : %d %d %d %d\n",ni,nj,r,c);
	if(ni<0 || ni>=r || nj<0 || nj>=c)	return false;
	if(map[ni][nj]=='#')	return false;
	return true;
}

int walkDist[20][20];
Cost getDP(const int si,const int sj,const int bi,const int bj){
	if(dp[si][sj][bi][bj].pushCost < MAX)	return dp[si][sj][bi][bj];
	//bfs to calculate walk cost to box's neighbors
	for(int i=0;i<r;++i)	for(int j=0;j<c;++j)	walkDist[i][j] = -1;
	queue<Position>Q;
	Position h,t;
	h.i=si, h.j=sj, walkDist[si][sj]=0;
	Q.push(h);
	while(!Q.empty()){
		h = Q.front();
		Q.pop();
		for(int k=0;k<4;++k){
			t.i = h.i + directI[k];
			t.j = h.j + directJ[k];
			if(!validPosition(t.i,t.j))	continue;
			if(t.i==bi && t.j==bj)	continue;//box cannot be crossed
			if(walkDist[t.i][t.j] != -1)	continue;//this point is visited
			walkDist[t.i][t.j] = walkDist[h.i][h.j] + 1;
			Q.push(t);
		}
	}//bfs end
	int walkDistBuffer[4];
	for(int i=0;i<4;++i){
		walkDistBuffer[i] = walkDist[bi - directI[i]][bj - directJ[i]];
	}
	
	//Dynamic Programming
	Cost min,tmp;
	min.pushCost = MAX;
	int chosenDir = -1;
	for(int di=0;di<4;++di){//4 directions by order
		int neighbourI = bi - directI[di];
		int neighbourJ = bj - directJ[di];
//		printf("%d %d %d %d %d %d %d\n",si,sj,bi,bj,neighbourI,neighbourJ,di);
		if(!validPosition(neighbourI,neighbourJ))	continue;//invalid
		if(walkDistBuffer[di] == -1)	continue;//unreachable
		int nextI = bi + directI[di];
		int nextJ = bj + directJ[di];
		if(!validPosition(nextI,nextJ))	continue;//cannot move in this direction
		if(pushAppear[bi][bj][di]){//calculated
			tmp = dp[bi][bj][nextI][nextJ];
		}
		else{
			pushAppear[bi][bj][di] = true;
			tmp = getDP(bi,bj,nextI,nextJ);
		}
//		printf("(%d,%d)->(%d,%d) : %d %d\n",bi,bj,nextI,nextJ,tmp.pushCost,tmp.walkCost);
		tmp.walkCost += walkDistBuffer[di];
		tmp.pushCost += 1;
		if(tmp < min){
			min = tmp;
			chosenDir = di;
		}
	}//DP end
	dp[si][sj][bi][bj] = min;
	directions[bi][bj] = chosenDir;
	return dp[si][sj][bi][bj];
}

void print(int si,int sj,int bi,int bj){
	if(bi==target.i && bj==target.j)	return;
	int d = directions[bi][bj];
	//bfs to get walk step
	int dirFrom[20][20];
	for(int i=0;i<r;++i)	for(int j=0;j<c;++j)	dirFrom[i][j] = -1;
	queue<Position>Q;
	Position h,t;
	h.i=si, h.j=sj;
	Q.push(h);
	while(!Q.empty()){
		h = Q.front();
		Q.pop();
		for(int k=0;k<4;++k){
			t.i = h.i + directI[k];
			t.j = h.j + directJ[k];
			if(!validPosition(t.i,t.j))	continue;
			if(t.i==bi && t.j==bj)	continue;//box cannot be crossed
			if(dirFrom[t.i][t.j] != -1)	continue;//this point is visited
			dirFrom[t.i][t.j] = k;
			Q.push(t);
		}
	}//bfs end
	string str="";
	int ti=bi-directI[d],tj=bj-directJ[d];
	while(ti!=si||tj!=sj){
		int df = dirFrom[ti][tj];
		str += directChar[0][df];
		ti -= directI[df];
		tj -= directJ[df];
	}
	for(int k = str.length()-1;k>=0;--k)	putchar(str[k]);
	putchar(directChar[1][d]);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int maze = 0;
	while(scanf("%d%d",&r,&c)!=EOF&&r>0&&c>0){
		++maze;
		initialize();
		Cost res;
		res = getDP(start.i,start.j,box.i,box.j);
		printf("Maze #%d\n",maze);
		if(res.pushCost < MAX){
//			printf("%d %d\n",res.pushCost,res.walkCost);
			while(box.i!=target.i || box.j!=target.j){
				print(start.i,start.j,box.i,box.j);
				start = box;
				int d = directions[box.i][box.j];
				box.i += directI[d];
				box.j += directJ[d];
			}
			printf("\n\n");
		}
		else printf("Impossible.\n\n");
	}
	return 0;
}
