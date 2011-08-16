#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#define MAX (1<<30)
#define MAXLEN 82
using namespace std;
int dp[MAXLEN][MAXLEN];
char op[MAXLEN][MAXLEN];
char str1[MAXLEN],str2[MAXLEN];
int l1,l2;

void getResult(){
	l1 = strlen(str1);
	l2 = strlen(str2);
	dp[0][0] = 0;
	for(int i=1;i<=l1;++i){
		dp[i][0] = i;
		op[i][0] = 'd';
	}
	for(int i=1;i<=l2;++i){
		dp[0][i] = i;
		op[0][i] = 'i';
	}
	for(int i=1;i<=l1;++i){
		for(int j=1;j<=l2;++j){
			if(str1[i] == str2[j]){
				dp[i][j] = dp[i-1][j-1];
				op[i][j] = ' ';
			}
			else{
				dp[i][j] = MAX;
			}
			if(dp[i][j] > dp[i-1][j]+1){
				dp[i][j] = dp[i-1][j]+1;
				op[i][j] = 'd';
			}
			if(dp[i][j] > dp[i-1][j-1]+1){
				dp[i][j] = dp[i-1][j-1]+1;
				op[i][j] = 'r';
			}
			if(dp[i][j] > dp[i][j-1]+1){
				dp[i][j] = dp[i][j-1]+1;
				op[i][j] = 'i';
			}
		}
	}
}

struct Operation{
	string opName;
	int pos;
	char target;
};

void print(){
	vector<Operation> ops;
	int i=l1,j=l2;
	Operation p;
	while(i>0||j>0){
		if(op[i][j]==' '){ --i;--j; }
		else if(op[i][j]=='d'){
			p.opName = "Delete";
			p.pos = i;
			ops.push_back(p);
			--i;
		}
		else if(op[i][j]=='r'){
			p.opName = "Replace";
			p.pos = i;
			p.target = str2[j];
			ops.push_back(p);
			--i;--j;
		}
		else if(op[i][j]=='i'){
			p.opName = "Insert";
			p.pos = i+1;
			p.target = str2[j];
			ops.push_back(p);
			--j;
		}
	}
	reverse(ops.begin(),ops.end());
	int offset = 0;
	for(int i=0;i<ops.size();++i){
		printf("%d %s %d",i+1,ops[i].opName.c_str(),ops[i].pos+offset);
		if(ops[i].opName=="Delete"){
			--offset;
		}
		else if(ops[i].opName=="Replace"){
			printf(",%c",ops[i].target);
		}
		else if(ops[i].opName=="Insert"){
			printf(",%c",ops[i].target);
			++offset;
		}
		printf("\n");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	str1[0] = str2[0] = ' ';
	while(scanf("%s%s",str1+1,str2+1)!=EOF){
		getResult();
/*		for(int i=0;i<=l1;++i){
			for(int j=0;j<=l2;++j){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",dp[l1][l2]);
		print();
	}
	return 0;
}
