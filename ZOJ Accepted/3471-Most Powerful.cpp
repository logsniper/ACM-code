#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#define MAX (1LL<<60)
#define MAXN 10
#define ABS(X) ((X)<0?(-(X)):(X))
using namespace std;

int n;
int dp[1<<MAXN];
int power[MAXN][MAXN];

void initialize(){
	for(int i=0;i<n;++i)	for(int j=0;j<n;++j)	scanf("%d",&power[i][j]);
	for(int i=0;i<(1<<n);++i)	dp[i] = -1;
	dp[0] = 0;
}

int getDP(int st){
	if(dp[st]>=0)	return dp[st];
	dp[st] = 0;
	for(int i=0;i<n;++i){
		if(((1<<i)&st)==0)	continue;
		for(int j=i+1;j<n;++j){
			if(((1<<j)&st)==0)	continue;
			if(dp[st] < power[i][j]+getDP(st^(1<<j)))
				dp[st] = power[i][j]+getDP(st^(1<<j));
			if(dp[st] < power[j][i]+getDP(st^(1<<i)))
				dp[st] = power[j][i]+getDP(st^(1<<i));
		}
	}
	return dp[st];
}

int main(){
	long s = clock();
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF && n>0){
		initialize();
		printf("%d\n",getDP((1<<n)-1));
	}
	long e = clock();
//	printf("initialize time = %.3f s\n",1.0f*(e-s)/CLOCKS_PER_SEC);
	return 0;
}
