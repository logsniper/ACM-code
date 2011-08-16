#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<30)
#define MAXN 2000
#define MAXM 1000
int M,L;
int n;
int capsity[MAXN+1];
int sum[MAXN+1];
int res[MAXM+1];
bool dp[MAXN+1][MAXM+1];
bool chooseM[MAXN+1][MAXM+1];

void getDP(){
	memset(dp,0,sizeof dp);
	memset(chooseM,0,sizeof chooseM);
	dp[0][0] = true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=M;++j){
			int Lcost = sum[i] - j;
			if(Lcost <= L && dp[i-1][j])	dp[i][j] = true;
			else if(j>=capsity[i]&&dp[i-1][j-capsity[i]]){
				dp[i][j] = true;
				chooseM[i][j] = true;
			}
		}
	}
}

void print(){
	int msize = 0;
	int mcost;
	for(mcost=0;mcost<=MAXM&&!dp[n][mcost];++mcost)	;
	if(mcost>MAXM){
		printf("Impossible to distribute\n");
		return ;
	}
	for(int i=n;i>0;--i){
		if(chooseM[i][mcost]){
			res[msize++] = i;
			mcost -= capsity[i];
		}
	}
	printf("%d",msize);
	for(int i=msize-1;i>=0;--i)	printf(" %d",res[i]);
	printf("\n");
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&M,&L)!=EOF && (M>0||L>0)){
		scanf("%d",&n);
		sum[0] = 0;
		for(int i=1;i<=n;++i){
			scanf("%d",&capsity[i]);
			sum[i] = sum[i-1] + capsity[i];
		}
		getDP();
		print();
	}
	return 0;
}
