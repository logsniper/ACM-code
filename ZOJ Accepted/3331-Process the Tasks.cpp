#include <cstdio>
#define INF 1000000
int cost[100][2];
const int offset = 100;
int dp[100][201],n;
int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d",&cost[i][0],&cost[i][1]);
		for(int i=0;i<n;++i)
			for(int j=0;j<201;++j)
				dp[i][j]=INF;
		dp[0][offset - cost[0][1]]=cost[0][1];
		dp[0][offset + cost[0][0]]=cost[0][0];
		for(int i=0;i<n-1;++i){
			for(int j=-100;j<0;++j){
				if(dp[i][j+offset]>=INF)	continue;
				if(dp[i+1][ j+cost[i+1][0]+offset ] > dp[i][j+offset]+((cost[i+1][0] + j)<0?0:(cost[i+1][0] + j)))
					dp[i+1][j+cost[i+1][0]+offset] = dp[i][j+offset]+((cost[i+1][0] + j)<0?0:(cost[i+1][0] + j));
				if(dp[i+1][ -cost[i+1][1]+offset ] > dp[i][j+offset] + cost[i+1][1])
					dp[i+1][-cost[i+1][1]+offset] = dp[i][j+offset]+cost[i+1][1];
			}
			for(int j=0;j<=100;++j){
				if(dp[i][j+offset]>=INF)	continue;
				if(dp[i+1][cost[i+1][0] + offset] > dp[i][j+offset] + cost[i+1][0])
					dp[i+1][cost[i+1][0] + offset] = dp[i][j+offset] + cost[i+1][0];
				if(dp[i+1][j-cost[i+1][1]+offset] > dp[i][j+offset] + ((cost[i+1][1] - j)<0?0:(cost[i+1][1] - j)))
					dp[i+1][j-cost[i+1][1]+offset] = dp[i][j+offset] + ((cost[i+1][1] - j)<0?0:(cost[i+1][1] - j));
			}
		}
// 		for(int i=0;i<n;++i)
// 			for(int j=-100;j<=100;++j)
// 				if(dp[i][j+offset]<INF)	printf("dp[%d][%d] = %d\n",i,j,dp[i][j+offset]);
		int min=INF;
		for(int i=0;i<=200;++i)
			if(min > dp[n-1][i])	min = dp[n-1][i];
		printf("%d\n",min);
	}
	return 0;
}