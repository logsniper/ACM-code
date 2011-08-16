#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX (1<<30)
using namespace std;

long long dp[3];
int n;
long long speed[100000];

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i)	scanf("%lld",&speed[i]);
		sort(speed,speed+n);
		if(n<=2){
			if(n==0)	printf("0\n");
			else if(n==1){
				printf("%lld\n",speed[0]);
			}
			else if(n==2){
				printf("%lld\n",speed[1]);
			}
			continue;
		}
		dp[0]=speed[1];dp[1]=speed[0]+speed[1]+speed[2];
		dp[2] = dp[1];
//		printf("init : %lld %lld\n",dp[0],dp[1]);
		for(int i=3;i<n;++i){
			if(dp[0]+speed[0]+speed[i]+speed[1]+speed[1]<dp[1]+speed[0]+speed[i])
				dp[2] = dp[0]+speed[0]+speed[i]+speed[1]+speed[1];
			else dp[2] = dp[1]+speed[0]+speed[i];
			dp[0] = dp[1];
			dp[1] = dp[2];
		}
		printf("%lld\n",dp[2]);
	}
	return 0;
}
