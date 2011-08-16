#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#define MAX (1<<30)
using namespace std;
int dp[101];
int c;
int a[101],p[101];
int sum[101];

void getResult(){
	dp[0] = 0;
	for(int i=1;i<=c;++i){
		dp[i] = MAX;
		for(int j=0;j<i;++j){
			if(dp[i] > dp[j]+(sum[i]-sum[j]+10)*p[i]){
				dp[i] = dp[j]+(sum[i]-sum[j]+10)*p[i];
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>c;
		sum[0] = 0;
		for(int i=1;i<=c;++i){
			cin>>a[i]>>p[i];
			sum[i] = sum[i-1] + a[i];
		}
		getResult();
		cout<<dp[c]<<endl;
	}
	return 0;
}
