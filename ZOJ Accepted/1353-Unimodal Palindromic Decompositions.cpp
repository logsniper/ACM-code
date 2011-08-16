#include<cstdio>
#include<cstring>
int n;
long long dp[250][250];
int done = 1;
int main(){
//	freopen("in.txt","r",stdin);
	memset(dp,0,sizeof dp);
	dp[1][1] = 1;
	int cas = 0;
	while(scanf("%d",&n)!=EOF&&n>0){
		for(int ni=done+1;ni<=n;++ni){
			for(int k=1;k<=ni/3;++k){
				for(int j=k;j<=ni/2-k;++j){
					dp[ni][k] += dp[ni-k*2][j];
				}
				dp[ni][k] += dp[ni-k*2][ni-k*2];
			}
			if(ni%2==0)	dp[ni][ni/2] = 1;
			dp[ni][ni] = 1;
		}
		done = done<n?n:done;
		long long res = dp[n][n];
		for(int i=1;i<=n/3;++i){
			res += dp[n][i];
		}
		if(n/2 != n/3)	res += dp[n][n/2];
		printf("%d %lld\n",n,res);
	}
	return 0;
}
