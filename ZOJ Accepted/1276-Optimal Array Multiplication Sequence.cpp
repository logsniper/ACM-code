#include<cstdio>
#include<cstring>
#define MAX (1<<30)

int dp[10][10];
int pos[10][10];
int n;
int w[10],h[10];

int getDP(int s,int e){
	if(dp[s][e] != -1){
		return dp[s][e];
	}
	int p=s,min=MAX;
	for(int i=s;i<e;++i){
		int tmp = getDP(s,i)+getDP(i+1,e)+w[s]*h[i]*h[e];
		if(min > tmp){
			min = tmp;
			p = i;
		}
	}
	dp[s][e] = min;
	pos[s][e] = p;
//	printf("dp[%d,%d]=%d\n",s,e,dp[s][e]);
	return dp[s][e];
}

void print(int s,int e){
	if(s==e){
		printf("A%d",s+1);
	}
	else{
		printf("(");
		print(s,pos[s][e]);
		printf(" x ");
		print(pos[s][e]+1,e);
		printf(")");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int cas = 0;
	while(scanf("%d",&n)&&n>0){
		++cas;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j] = -1;
		for(int i=0;i<n;++i){
			scanf("%d%d",&w[i],&h[i]);
			dp[i][i] = 0;
			pos[i][i] = i;
		}
		getDP(0,n-1);
		printf("Case %d: ",cas);
		print(0,n-1);
		printf("\n");
	}
	return 0;
}
