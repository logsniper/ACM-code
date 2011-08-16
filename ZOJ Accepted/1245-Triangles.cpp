#include<cstdio>
#include<cstring>
#define MAX (1<<30)
int n;
char matrix[100][200];
bool valid[2][200][200];
int maxLength;
int initialize(){
	maxLength = 0;
	memset(matrix,0,sizeof matrix);
	for(int i=0;i<n;++i){
		scanf("%s",&matrix[i][i]);
	}
}

void getResult(){
	memset(valid,0,sizeof valid);
	for(int j=0;j<2*n-1;++j){
		if(matrix[0][j]=='-'){
			maxLength = 1;
			valid[0][j][j] = true;
		}
	}
	for(int i=1;i<n;++i){
		memset(valid[1],0,sizeof valid[1]);
		for(int j=i+1;j<2*n-2-i;j+=2){
			if(matrix[i][j]=='-')	valid[1][j][j] = true;
			else continue;
			for(int k=j+2;k<2*n-2-i;k+=2){
				if(matrix[i][k-1]=='#'||matrix[i][k]=='#')	break;
//				if(matrix[i-1][k-1]=='#')	break;
				if(!valid[0][j+1][k-1])	break;
				valid[1][j][k] = true;
				if(maxLength < k-j+1)	maxLength = k-j+1;
			}
		}
		memcpy(valid[0],valid[1],sizeof valid[1]);
	}
	
	memset(valid,0,sizeof valid);
	if(matrix[n-1][n-1]=='-')	valid[0][n-1][n-1] = true;
	for(int i=n-2;i>=0;--i){
		memset(valid[1],0,sizeof valid[1]);
		for(int j=i;j<2*n-1-i;j+=2){
			if(matrix[i][j]=='-')	valid[1][j][j] = true;
			else continue;
			for(int k=j+2;k<2*n-1-j;k+=2){
				if(matrix[i][k-1]=='#'||matrix[i][k]=='#')	break;
//				if(matrix[i+1][k-1]=='#')	break;
				if(!valid[0][j+1][k-1])	break;
				valid[1][j][k] = true;
				if(maxLength < k-j+1)	maxLength = k-j+1;
			}
		}
		memcpy(valid[0],valid[1],sizeof valid[1]);
	}
}


int main(){
//	freopen("in.txt","r",stdin);
	int cas = 0;
	while(scanf("%d",&n)!=EOF && n>0){
		initialize();
		getResult();
		printf("Triangle #%d\n",++cas);
		printf("The largest triangle area is %d.\n\n",(maxLength+1)*(maxLength+1)/4);
	}
	return 0;
}
