#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<29)

int n,k;
int repeat[10][10];
int flightPrice[10][10][30];
int dp[2][10];

void initialize(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(j==i)	continue;
			scanf("%d",&repeat[i][j]);
			for(int k=0;k<repeat[i][j];++k){
				scanf("%d",&flightPrice[i][j][k]);
				if(flightPrice[i][j][k]==0)	flightPrice[i][j][k]=MAX;
			}
		}
	}
}

int getDP(){
	dp[0][0] = 0;
	for(int i=1;i<n;++i){
		dp[0][i] = MAX;
	}
	for(int ki=1;ki<=k;++ki){
		for(int i=0;i<n;++i){
			dp[1][i] = MAX;
			for(int j=0;j<n;++j){
				if(j==i)	continue;
				int tmp = dp[0][j] + flightPrice[j][i][(ki-1)%repeat[j][i]];
				if(dp[1][i] > tmp)	dp[1][i] = tmp;
			}
		}
		memcpy(dp[0],dp[1],sizeof dp[1]);
	}
	return dp[1][n-1];
}

int main(){
//	freopen("in.txt","r",stdin);
	int cas = 0;
	while(scanf("%d%d",&n,&k)!=EOF&&n>0&&k>0){
		++cas;
		initialize();
		int res = getDP();
		printf("Scenario #%d\n",cas);
		if(res < MAX)	printf("The best flight costs %d.\n\n",res);
		else printf("No flight possible.\n\n");
	}
	return 0;
}
