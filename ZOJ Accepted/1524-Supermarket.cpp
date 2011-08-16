#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<30)
#define MAXN 100000
#define MAXM 100

int M,N;
int list[MAXM+1];
int item[MAXN+1];
float price[MAXN+1];

float dp[2][MAXN+1];
void getResult(){
	for(int i=0;i<=N;++i)	dp[0][i] = 0.0f;
	for(int mi=1;mi<=M;++mi){
		for(int j=0;j<mi;++j)	dp[1][j] = MAX;
		for(int j=mi;j<=N;++j){
			dp[1][j] = MAX;
			if(dp[1][j] > dp[1][j-1])	dp[1][j] = dp[1][j-1];
			if(list[mi]==item[j] && dp[1][j] > dp[0][j-1]+price[j]){
				dp[1][j] = dp[0][j-1]+price[j];
			}
//			printf("(%d,%d,%.2f) ",mi,j,dp[1][j]);
		}
//		printf("\n");
		memcpy(dp[0],dp[1],sizeof dp[1]);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&M,&N)!=EOF && (M>0||N>0)){
		for(int i=1;i<=M;++i)	scanf("%d",&list[i]);
		for(int i=1;i<=N;++i)	scanf("%d%f",&item[i],&price[i]);
		getResult();
		if(dp[1][N] < MAX){
			printf("%.2f\n",dp[1][N]);
		}
		else	printf("Impossible\n");
	}
	return 0;
}
