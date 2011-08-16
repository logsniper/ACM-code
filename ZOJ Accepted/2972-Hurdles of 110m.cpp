#include <cstdio>
#define INF 1000000
int dp[2][120];
int forcecost[3],timecost[3];
int main()
{
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			dp[0][i]=INF;
		}
		dp[0][m]=0;
		for(int i=0;i<n;++i){
			int thisstep=i%2,nextstep=1-thisstep;
			scanf("%d%d%d%d%d",timecost,timecost+1,timecost+2,forcecost,forcecost+2);
			forcecost[1]=0;forcecost[2]=-forcecost[2];
			for(int j=0;j<=m;++j){
				dp[nextstep][j]=INF;
			}
			for(int j=0;j<=m;++j){
				if(dp[thisstep][j]==INF)		continue;
				for(int k=0;k<3;++k){
					if(j-forcecost[k]>=0&&j-forcecost[k]<=m&&dp[thisstep][j]+timecost[k]<dp[nextstep][j-forcecost[k]]){
						dp[nextstep][j-forcecost[k]]=dp[thisstep][j]+timecost[k];
					}
					else if(j-forcecost[k]>m&&dp[thisstep][j]+timecost[k]<dp[nextstep][m]){
						dp[nextstep][m]=dp[thisstep][j]+timecost[k];
					}
				}
			}
		}
		int min=INF;
		for(int i=0;i<=m;++i)
			if(dp[n%2][i]<min)		min=dp[n%2][i];
		printf("%d\n",min);
	}
	return 0;
}