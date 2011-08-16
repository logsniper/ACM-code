#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX (1LL<<60)
#define MAXN 8
#define ABS(X) ((X)<0?(-(X)):(X))
using namespace std;

int n,m;
int dp[9][49];

int main(){
//	freopen("in.txt","r",stdin);
	memset(dp,0,sizeof dp);
	for(int j=1;j<=6;++j)	dp[1][j] = 1;
	for(int i=2;i<=8;++i){
		for(int j=1;j<=48;++j){
			for(int k=1;k<=6;++k){
				if(j<k)	continue;
				dp[i][j] += dp[i-1][j-k];
			}
//			printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	while(scanf("%d%d",&n,&m)!=EOF){
		int sum[49],s1=0,s2=0;
		sum[0] = 0;
		for(int i=1;i<=48;++i){
			sum[i] = sum[i-1] + dp[n][i];
			s1 += dp[n][i];
			s2 += dp[m][i];
		}
		double res = 0.0;
		for(int i=1;i<=48;++i){
			res += (1.0*dp[m][i]/s2)*(1.0*(sum[48]-sum[i])/s1);
		}
		printf("%lf\n",res);
	}
	return 0;
}
