#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100;

int nx, ny;
bool matrix[MAXN][MAXN];
int cx[MAXN],cy[MAXN];
vector<vector<int> > adj;
bool visited[2][MAXN];

bool dfs(int x){
	//printf("visiting %d\n",x);
	bool ret = false;
	visited[0][x] = true;
	for(int i=0;i<adj[x].size();++i){
		int y = adj[x][i];
		if( !visited[1][y]){
			if(cy[y] >= 0 && !visited[0][cy[y]]){
				visited[1][y] = true;
				ret = dfs(cy[y]);
				if(ret){
					cx[x] = y;
					cy[y] = x;
					break;
				}
			} else if(cy[y] < 0){
				ret = true;
				cx[x] = y;
				cy[y] = x;
				break;
			}
		}
	}
	return ret;
}

void init(){
	for(int i=0;i<nx;++i)	cx[i] = -1;
	for(int i=0;i<ny;++i)	cy[i] = -1;
	memset(visited,0,sizeof visited);
	adj.clear();
	for(int i=0;i<nx;++i){
		vector<int> v_col;
		for(int j=0;j<ny;++j){
			if(matrix[i][j])	v_col.push_back(j);
		}
		adj.push_back(v_col);
	}
}

int hungary(){
	init();
	for(int i=0;i<nx;++i){
		if(cx[i] < 0){
			memset(visited,0,sizeof visited);
			if(!dfs(i))	break;
		}
	}
	int count = 0;
	for(int i=0;i<nx;++i){
		if(cx[i] >=0 )	++ count;
	}
	return count;
}

int main(){
	int L;
	scanf("%d%d%d",&nx,&ny,&L);
	memset(matrix,0,sizeof matrix);
	for(int i=0;i<L;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		matrix[x][y] = true;
	}
	printf("matched pairs count : %d\n",hungary());
	for(int i=0;i<nx;++i){
		if(cx[i] >=0)	printf("%d - %d\n",i,cx[i]);
	}
}
