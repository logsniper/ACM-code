#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAXN 82
#define MAX (1<<30)
char str[MAXN];
int dp[MAXN][MAXN];
int len;

bool lessThan(int ai,int aj,int bi,int bj){
	while(ai<aj&&str[ai]=='0')	++ai;
	while(bi<bj&&str[bi]=='0')	++bi;
	if(aj-ai!=bj-bi)
		return aj-ai<bj-bi;
	else{
		for(int i=0;ai+i<=aj;++i){
			if(str[ai+i] != str[bi+i])	return str[ai+i] < str[bi+i];
		}
	}
	return false;
}

void getResult(){
	len = strlen(str);
	dp[0][0] = 1;
	for(int i=1;i<len;++i){
		dp[0][i] = 1;
		for(int j=0;j<len;++j){
			dp[i][j] = -1;
		}
	}
	for(int i=0;i<len;++i){
		for(int j=i;j<len;++j){
			if(dp[i][j] < 0)	continue;
			for(int k=j+1;k<len;++k){
				if((dp[j+1][k]==-1 || dp[j+1][k]>dp[i][j]+1) && lessThan(i,j,j+1,k)){
					dp[j+1][k] = dp[i][j]+1;
				}
			}
		}
	}
/*	for(int i=0;i<len;++i){
		for(int j=0;j<len;++j)	printf("%d ",dp[i][j]);
		printf("\n");
	}*/
}

void print(){
	int s,e,minseg=MAX;
	char buffer[MAXN];
	vector<string> res;
	
	e = len-1;
	for(s=e;s>=0&&dp[s][e]==-1;--s){}
	minseg = dp[s][e];
	for(int i=s-1;i>=0&&str[i]=='0';--i){
		if(dp[i][len-1]!=-1 && dp[i][len-1]<minseg){
			minseg = dp[i][len-1];
			s = i;
		}
	}
	memset(buffer,0,sizeof buffer);
	memcpy(buffer,str+s,e-s+1);
	res.push_back(buffer);
	e = s-1;
	--minseg;
	while(e>=0){
		for(s=e;s>=0&&dp[s][e]!=minseg;--s){}
		memset(buffer,0,sizeof buffer);
		memcpy(buffer,str+s,e-s+1);
		res.push_back(buffer);
		e = s-1;
		--minseg;
	}
	reverse(res.begin(),res.end());
	for(int i=0;i<res.size();++i){
		if(i>0)	putchar(',');
		printf("%s",res[i].c_str());
	}
	printf("\n");
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		if(strcmp(str,"0") == 0)	break;
		getResult();
		print();
	}
	return 0;
}
