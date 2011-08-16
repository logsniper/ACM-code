#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
string res[101][101];
int dp[101][101];
string target;
int n;

void getResult(){
	char number[4];
	n = target.length();
	for(int i=0;i<n;++i){
		dp[i][i+1] = 1;
		res[i][i+1] = target[i];
	}
	for(int step=2;step<=n;++step){
		for(int i=0;i+step<=n;++i){
			res[i][i+step] = target.substr(i,step);
			dp[i][i+step] = step;
			for(int k=1;k<=step/2;++k){
				
				if(dp[i][i+step] > dp[i][i+k]+dp[i+k][i+step]){
					dp[i][i+step] = dp[i][i+k]+dp[i+k][i+step];
					res[i][i+step] = res[i][i+k]+res[i+k][i+step];
				}
				if(dp[i][i+step] > dp[i][i+step-k]+dp[i+step-k][i+step]){
					dp[i][i+step] = dp[i][i+step-k]+dp[i+step-k][i+step];
					res[i][i+step] = res[i][i+step-k]+res[i+step-k][i+step];
				}
				
				if(step%k!=0)	continue;
				bool flag = true;
				for(int s=k;s<step;++s){
					if(target[i+s]!=target[i+s%k]){
						flag = false;
						break;
					}
				}
				if(flag){
					memset(number,0,sizeof number);
					int t = step/k;
					sprintf(number,"%d",t);
					if(dp[i][i+step] > strlen(number)+2+dp[i][i+k]){
						dp[i][i+step] = strlen(number)+2+dp[i][i+k];
						res[i][i+step] = string(number)+"("+res[i][i+k]+")";
					}
				}
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	while(cin>>target){
		getResult();
		cout<<res[0][target.length()]<<endl;
	}
	return 0;
}
