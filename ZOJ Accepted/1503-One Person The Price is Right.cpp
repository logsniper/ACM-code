#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<30)
#define MAXN 30
#define MOD 10000007
int n;
int dp[MAXN+1][MAXN+1];
int main(){
//	freopen("in.txt","r",stdin);
	for(int i=0;i<=MAXN;++i){
		dp[i][0] = i;
		dp[0][i] = 0;
	}
	for(int j=1;j<=MAXN;++j){
		for(int i=1;i<=MAXN;++i){
			dp[i][j] = dp[i-1][j-1]+1+dp[i-1][j];
		}
	}
	
	dp[0][0] = 1;
	int G,L;
	int cas = 0;
	while(scanf("%d%d",&G,&L)!=EOF && (G>0||L>0)){
		++cas;
		printf("Case %d: %d\n",cas,dp[G][L]);
	}
	return 0;
}
