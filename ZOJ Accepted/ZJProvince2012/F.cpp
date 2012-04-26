#include <cstdio>
#include <cstring>

long long dp[51][51][51];
int pair[51][2];

int main(){
	int T;
	scanf("%d",&T);
	while(T -- ){
		int n,m,k,s;
		scanf("%d%d%d%d",&n,&m,&k,&s);
		memset(dp,0,sizeof dp);
		dp[0][0][s] = 1;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&pair[i][0],&pair[i][1]);
			for(int t=0;t<=n;++t)	dp[i][0][t] = dp[0][0][t];
			for(int j=1;j<=k && j<=i;++j){
				for(int t=1;t<=n;++t){
					if(t == pair[i][1]){
						dp[i][j][t] = dp[i-1][j][t] + dp[i-1][j-1][pair[i][0]];
					} else if (t == pair[i][0]){
						dp[i][j][t] = dp[i-1][j][t] + dp[i-1][j-1][pair[i][1]];
					} else {
						dp[i][j][t] = dp[i-1][j-1][t] + dp[i-1][j][t];
					}
				}
			}
		}
		int maxp = 0;
		for(int i=1;i<=n;++i){
			if(dp[m][k][maxp] < dp[m][k][i]){
				maxp = i;
			}
		}
		printf("%d\n",maxp);
	}
}
