#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<30)
#define MAXN 100
#define MOD 10000007
int n;
long long dp[MAXN+1][MAXN+1];
char map[MAXN+1][MAXN+2];
int type1,type2;

bool initialize(){
	for(int i=0;i<n;++i){
		scanf("%s",map[i]);
	}
	type1 = type2 = 0;
	for(int i=0;i<n;++i){
		int c = 0, r = 0;
		for(int j=0;j<n;++j){
			if(map[i][j]=='Y')	++r;
			if(map[j][i]=='Y')	++c;
		}
		if(c>1 || r>1)	return false;
		if(c==0){
			if(r==1)	++type1;
			else	++type2;
		}
	}
	return true;
}

long long getDP(int x,int y){
	if(dp[x][y] >=0)	return dp[x][y];
	dp[x][y] = 0;
	if(y>=2)	dp[x][y] += getDP(x,y-2)*(y-1);
	if(y>=1)	dp[x][y] += getDP(x,y-1)*(x+y-1);
	else if(x>=1)	dp[x][y] += getDP(x-1,y)*(x+y);
	dp[x][y] %= MOD;
//	printf("%d %d %lld\n",x,y,dp[x][y]);
	return dp[x][y];
}

int main(){
//	freopen("in.txt","r",stdin);
	for(int i=0;i<=MAXN;++i)	for(int j=0;j<=MAXN;++j)	dp[i][j] = -1;
	dp[0][0] = 1;
	while(scanf("%d",&n)!=EOF && n>0){
		if(initialize()){
			printf("%lld\n",getDP(type1,type2));
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
