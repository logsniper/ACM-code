#include<cstdio>
int card[100];
int dp[100][100];
void getdp(int n)
{
	int step,i,j;
	for(i=0;i<n-1;++i)
		dp[i][i+1]=0;
	for(i=0;i<n-2;++i)
		dp[i][i+2]=card[i]*card[i+1]*card[i+2];
	for(step=3;step<=n-1;++step){
		for(i=0;step+i<=n-1;++i){
			int score_tmp=int(1E8);
			int multi=card[i]*card[i+step];
			for(j=1;j<step;++j)
				if(dp[i][i+j]+dp[i+j][i+step]+multi*card[i+j]<score_tmp)
					score_tmp=dp[i][i+j]+dp[i+j][i+step]+multi*card[i+j];
			dp[i][i+step]=score_tmp;
		}
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&card[i]);
		getdp(n);
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
