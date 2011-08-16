#include<cstdio>
#include<cstring>
#define MAX (1<<30)
int dp[100][100];
int prev[2][100][100];//prev[0][i][j]表示第一行下标0-i中值为j的最后一个位置 
int n,m;
int line[2][100];

void initialize(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&line[0][i]);
		for(int j=0;j<100;++j){
			if(i==0)	prev[0][i][j] = -1;
			else prev[0][i][j] = prev[0][i-1][j];
		}
		prev[0][i][line[0][i]] = i;
	}
	for(int i=0;i<m;++i){
		scanf("%d",&line[1][i]);
		for(int j=0;j<100;++j){
			if(i==0)	prev[1][i][j] = -1;
			else prev[1][i][j] = prev[1][i-1][j];
		}
		prev[1][i][line[1][i]] = i;
	}
	memset(dp,0,sizeof dp);
}

void getDP(){
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			int s = dp[i-1][j]<dp[i][j-1]?dp[i][j-1]:dp[i-1][j];
			int p1 = prev[0][i-1][line[1][j]];
			int p2 = prev[1][j-1][line[0][i]];	
			if(line[0][i]!=line[1][j] && p1>=0 && p2>=0){
				if(p1>0 && p2>0){
					if(s < dp[p1-1][p2-1]+2)	s = dp[p1-1][p2-1]+2;
				}
				else{
					s = 2;
				}
			}
			dp[i][j] = s;
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		initialize();
		getDP();
		printf("%d\n",dp[n-1][m-1]);
	}
}
