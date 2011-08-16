#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define MAX (1<<30)
#define MAXN 16
int size;
map<string,int> mp;
bool path[MAXN][MAXN];
int dp[1<<MAXN];

int getDP(int st){
	if(dp[st]>=0)	return dp[st];
	dp[st] = 0;
	for(int i=0;i<size;++i){
		if((st&(1<<i))==0)	continue;
		bool in = false;
		for(int j=0;j<size;++j){
			if((st&(1<<j))>0 && path[j][i]){
				in = true;
				break;
			}			
		}
		if(!in)	dp[st] += getDP(st^(1<<i));
	}
	return dp[st];
}

int main(){
//	freopen("in.txt","r",stdin);
	int n;
	string str1,str2;
	while(cin>>n){
		mp.clear();
		size = 0;
		memset(path,0,sizeof path);
		dp[0] = 1;
		for(int i=0;i<n;++i){
			cin>>str1>>str2;
			if(mp[str1]==0)	mp[str1] = ++size;
			if(mp[str2]==0)	mp[str2] = ++size;
			path[mp[str1]-1][mp[str2]-1] = 1;
		}
/*		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j){
				cout<<path[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1;i<(1<<size);++i)	dp[i]=-1;
		cout<<getDP((1<<size)-1)<<endl;
	}
	return 0;
}
