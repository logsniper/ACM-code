#include<cstdio>
#include<cstring>
#define MAX (1<<30)
int dp[2][5001];
int k,n;
int sticks[5001];

int main(){
//	freopen("in.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&k,&n);
		k+=8;
		for(int i=1;i<=n;++i){
			scanf("%d",&sticks[i]);
		}
		for(int i=0;i<2;++i)
			for(int j=0;j<=n;++j)
				dp[i][j] = MAX;
		int min = MAX;
		for(int i=2;i<=n;++i){
			if(i<n-3*(k-1) && min>(sticks[i]-sticks[i-1])*(sticks[i]-sticks[i-1])){
				min = (sticks[i]-sticks[i-1])*(sticks[i]-sticks[i-1]);
			}
			dp[0][i] = min;
		}
		for(int ki=2;ki<=k;++ki){
			for(int i=0;i<=n;++i){
				int a = MAX, b = MAX;
				if(i>2*ki)
					a = dp[1][i-1];
				if(i>=2*ki && i<n-3*(k-ki))
					b = dp[0][i-2]+(sticks[i]-sticks[i-1])*(sticks[i]-sticks[i-1]);
				dp[1][i] = a<b?a:b;
			}
			memcpy(dp[0],dp[1],sizeof dp[1]);
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
