#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define MAX (1<<30)
using namespace std;

const int Node = 21;
const int Leaf = 21;
const int Height = 10;
int dp[Node][Leaf][Height];

int getDP(int n,int l,int h){
	if(dp[n][l][h]>=0)	return dp[n][l][h];
	dp[n][l][h] = 0;
	if(n<l || n<h || n<=0 || l<=0 || h<=0)	return dp[n][l][h];
	for(int n1=1;n1<n-1;++n1){
		for(int l1=1;l1<=l;++l1){
			dp[n][l][h] += getDP(n1,l1,h-1)*getDP(n-1-n1,l-l1,h-1);
			dp[n][l][h] += getDP(n1,l1,h-1)*getDP(n-1-n1,l-l1,h-2);
			dp[n][l][h] += getDP(n1,l1,h-2)*getDP(n-1-n1,l-l1,h-1);
		}
	}
//	if(dp[n][l][h])	printf("%d %d %d %d\n",n,l,h,dp[n][l][h]);
	return dp[n][l][h];
}

int main(){
//	freopen("in.txt","r",stdin);
	for(int i=0;i<Node;++i)	for(int j=0;j<Leaf;++j)
			for(int k=0;k<Height;++k)	dp[i][j][k] = -1;
	dp[1][1][1] = 1;
	dp[2][1][2] = 2;
	int n,l;
	while(scanf("%d%d",&n,&l)!=EOF){
		int res = 0;
		for(int i=1;i<Height;++i){
			res += getDP(n,l,i);
		}
		printf("%d\n",res);
	}
	return 0;
}
