#include<cstdio>
#include<cstring>
#define MAX (1<<29)
#define MAXN 1000
int n;
int *dp[13];
int fire,amount,hire;
int month[13];
int maxAmount;
int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF && n>0){
		scanf("%d%d%d",&hire,&amount,&fire);
		maxAmount = 0;
		month[0] = 0;
		for(int i=1;i<=n;++i){
			scanf("%d",&month[i]);
			if(maxAmount < month[i])	maxAmount = month[i];
		}
		for(int i=0;i<=n;++i)	dp[i] = new int[maxAmount+1];
		for(int i=0;i<=n;++i)	for(int j=0;j<=maxAmount;++j)	dp[i][j] = MAX;
		for(int j=0;j<=maxAmount;++j)	dp[0][j]=hire*j;
		for(int m=1;m<=n;++m){
			for(int left=month[m];left<=maxAmount;++left){
				for(int j=month[m-1];j<left;++j){
					if(dp[m][left] > dp[m-1][j]+(left-j)*hire+left*amount){
						dp[m][left] = dp[m-1][j]+(left-j)*hire+left*amount;
					}
				}
				for(int j=left<month[m-1]?month[m-1]:left;j<=maxAmount;++j){
					if(dp[m][left] > dp[m-1][j]+(j-left)*fire+left*amount){
						dp[m][left] = dp[m-1][j]+(j-left)*fire+left*amount;
					}
				}
			}
/*			printf("month : %d\n",m);
			for(int i=month[m];i<=maxAmount;++i){
				printf(" left = %d, cost = %d\n",i,dp[m][i]);
			}*/
		}
		int res = MAX;
		for(int i=month[n];i<=maxAmount;++i){
			if(res > dp[n][i])	res = dp[n][i];
		}
		printf("%d\n",res);
		for(int i=0;i<=n;++i){
			delete dp[i];
		}
	}
	return 0;
}

