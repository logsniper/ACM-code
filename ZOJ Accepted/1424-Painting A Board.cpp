#include<cstdio>
#include<cstring>
#define MAX (1<<30)
int dp[1<<15][20];
int n;
bool colors[20];
class Rectangle{
public:
	int left,up;
	int down,right;
	int color;
	bool affectMe(const Rectangle &b) const{
		if(up == b.down){
			if(b.right<=left || b.left>=right){
				return false;
			}
			return true;
		}
		return false;
	}
}rec[15];
bool AaffectB[15][15];

void initialize(){
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<20;++j){
			dp[i][j] = -1;
		}
	}
	memset(colors,0,sizeof colors);
	for(int i=0;i<n;++i){
		scanf("%d%d%d%d%d",&rec[i].up,&rec[i].left,&rec[i].down,&rec[i].right,&rec[i].color);
		--rec[i].color;
		colors[rec[i].color] = true;
		if(rec[i].up==0){
			dp[1<<i][rec[i].color] = 1;
		}
	}
	memset(AaffectB,0,sizeof AaffectB);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			AaffectB[i][j] = rec[j].affectMe(rec[i]);
		}
	}
}

bool checkState(int st,int id){
//	if(rec[id].up == 0)	return true;
	for(int i=0;i<n;++i){
		if((st&(1<<i))>0){
			if(AaffectB[id][i])	return false;
		}
	}
	return true;
}

int getDP(const int st,const int color){
	if(dp[st][color]>0)	return dp[st][color];
	int min = MAX;
	for(int add=0;add<n;++add){
		if((st&(1<<add))==0)	continue;
		if(rec[add].color != color)	continue;
		int nextst = (st^(1<<add));
		if(!checkState(nextst,add))	continue;
		if(min > getDP(nextst,color))	min = getDP(nextst,color);
		for(int c=0;c<20;++c){
			if(!colors[c])	continue;
			if(min > getDP(nextst,c)+1){
				min = getDP(nextst,c)+1;
			}
		}
	}
	dp[st][color] = min;
//	if(min<MAX)	printf("%d %d %d\n",st,color,min);
	return dp[st][color];
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		initialize();
		int res = MAX;
		int finalState = (1<<n)-1;
		for(int i=0;i<20;++i){
			if(colors[i]){
				if(res > getDP(finalState,i)){
					res = getDP(finalState,i);
				}
			}
		}
		printf("%d\n",res);
	}
}
