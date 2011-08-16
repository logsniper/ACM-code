#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define MAX (1<<30)
#define MAXLEN 102
using namespace std;

string stri;
char str[MAXLEN];
int dp[MAXLEN][MAXLEN];
string res[MAXLEN][MAXLEN];

string getres(int i,int j){
	if(i<=j)	return res[i][j];
	else	return "";
}

void getResult(){
	int len = stri.length();
	for(int i=0;i<len;++i){
		dp[i][i] = 2;
		if(stri[i] == '(' || stri[i] == ')')	res[i][i] = "()";
		else if(stri[i] == '[' || stri[i] == ']')	res[i][i] = "[]";
	}
	for(int step = 2;step<=len;++step){
		for(int i=0;i+step<=len;++i){
			if(stri[i]=='('&&stri[i+step-1]==')'){
				dp[i][i+step-1] = dp[i+1][i+step-2] + 2;
				res[i][i+step-1] = "("+getres(i+1,i+step-2)+")";
			}
			else if(stri[i]=='['&&stri[i+step-1]==']'){
				dp[i][i+step-1] = dp[i+1][i+step-2] + 2;
				res[i][i+step-1] = "["+getres(i+1,i+step-2)+"]";
			}
			else dp[i][i+step-1] = MAX;
			for(int j=i;j<i+step-1;++j){
				if(dp[i][i+step-1] > dp[i][j]+dp[j+1][i+step-1]){
					dp[i][i+step-1] = dp[i][j]+dp[j+1][i+step-1];
					res[i][i+step-1] = res[i][j]+res[j+1][i+step-1];
				}
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;++i){
		getchar();
		gets(str);
		stri = str;
		getResult();
		if(stri.length()>0)	printf("%s\n",res[0][stri.length()-1].c_str());
		else	printf("\n");
		if(i<n)	printf("\n");
	}
	return 0;
}
