#include <cstdio>
int mm[1000000],n;
int dp[3][1000000];
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&mm[i]);
		}
		dp[1][0]=dp[2][0]=dp[2][1]=0;
		dp[0][0]=mm[0];
		dp[1][1]=mm[1];
		dp[2][2]=mm[2];
		dp[0][1]=mm[0]>mm[1]?mm[0]:mm[1];
		dp[1][2]=mm[2]>mm[1]?mm[2]:mm[1];
		dp[0][2]=(mm[0]+mm[2])>mm[1]?(mm[0]+mm[2]):mm[1];
		for(int i=3;i<n;++i){
			int tmp=dp[0][i-2]>dp[0][i-3]?dp[0][i-2]:dp[0][i-3];
			dp[0][i]=tmp+mm[i];
			tmp=dp[1][i-2]>dp[1][i-3]?dp[1][i-2]:dp[1][i-3];
			dp[1][i]=tmp+mm[i];
			tmp=dp[2][i-2]>dp[2][i-3]?dp[2][i-2]:dp[2][i-3];
			dp[2][i]=tmp+mm[i];
		}
		int max=dp[0][n-3]>dp[0][n-2]?dp[0][n-3]:dp[0][n-2];
		max=max>dp[1][n-2]?max:dp[1][n-2];
		max=max>dp[1][n-1]?max:dp[1][n-1];
		max=max>dp[2][n-1]?max:dp[2][n-1];
		printf("%d\n",max);
	}
	return 0;
}