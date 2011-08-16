#include<cstdio>
#include<cstring>
#define MAX (1<<30)
#define MAXN 500
#define ABS(X) ((X)<0?(-(X)):(X))

int n,m,K;
double aver;
//dp[0][i]为按要求完成前i个任务所需最少机器人数量
//dp[1][i]为按要求完成前i个任务所需最多机器人数量 
int dp[2][MAXN+1]; 
int tasks[MAXN+1];
int sum[MAXN+1];

void initialize(){
	sum[0] = 0;
	for(int i=1;i<=m;++i){
		scanf("%d",&tasks[i]);
		sum[i] = sum[i-1] + tasks[i];
		
	}
	aver = 1.0*sum[m]/n;
}

void gao(){
	dp[0][0] = 0;
	dp[1][0] = 0;
	for(int i=1;i<=m;++i){
		dp[0][i] = MAX;
		dp[1][i] = -1;
		for(int j=i;j>0;--j){
			if(sum[i]-sum[j-1]<aver-K)	continue;
			if(sum[i]-sum[j-1]>aver+K)	break;
			if(dp[0][j-1]!=MAX && dp[0][i] > dp[0][j-1]+1)	dp[0][i] = dp[0][j-1]+1;
			if(dp[1][j-1]!=-1 && dp[1][i] < dp[1][j-1]+1)	dp[1][i] = dp[1][j-1]+1;
		}
	}
/*	for(int i=0;i<=m;++i)	printf("%d ",dp[0][i]);
	printf("\n");
	for(int i=0;i<=m;++i)	printf("%d ",dp[1][i]);
	printf("\n");*/
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&K)!=EOF){
		initialize();
		gao();
		if(n>=dp[0][m] && n<=dp[1][m]){
			printf("possible\n");
		}
		else if(dp[1][m]>0 && n>dp[1][m] && aver<=K){
			printf("possible\n");
		}
		else{
			printf("impossible\n");
		}
	}
	return 0;
}
