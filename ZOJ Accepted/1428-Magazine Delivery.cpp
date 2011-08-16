#include<cstdio>
#include<cstring>
#define MAX (1<<30)
int dp[30][30][30];
int n;
int dist[30][30];

void initialize(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		dist[i][i] = 0;
		for(int j=i+1;j<n;++j){
			scanf("%d",&dist[i][j]);
			dist[j][i] = dist[i][j];
		}
	}
	//Floyd shortest path
	//wrong answer with Floyd
/*	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}*/
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k){
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
}

int getDP(int a,int b,int c){
	if(dp[a][b][c] >= 0)	return dp[a][b][c];
	int min = MAX;
	int m = ((a>b)?a:b)>c?((a>b)?a:b):c; 
	if(m==a){
		if(b<m-1&&c<m-1){
			if(min>getDP(a-1,b,c)+dist[a-1][a])	min = getDP(a-1,b,c)+dist[a-1][a];
		}
		else{
			for(int i=0;i<a;++i){
				if(min > getDP(i,b,c)+dist[i][a])
					min = getDP(i,b,c)+dist[i][a];
			}
		}
	}
	if(m==b){
		if(a<m-1&&c<m-1){
			if(min>getDP(a,b-1,c)+dist[b-1][b])	min = getDP(a,b-1,c)+dist[b-1][b];
		}
		else{
			for(int i=0;i<b;++i){
				if(min > getDP(a,i,c)+dist[i][b])
					min = getDP(a,i,c)+dist[i][b];
			}
		}
	}
	if(m==c){
		if(a<m-1&&b<m-1){
			if(min>getDP(a,b,c-1)+dist[c-1][c])	min = getDP(a,b,c-1)+dist[c-1][c];
		}
		else{
			for(int i=0;i<c;++i){
				if(min > getDP(a,b,i)+dist[i][c])
					min = getDP(a,b,i)+dist[i][c];
			}
		}
	}
	
	dp[a][b][c] = min;
	return min;
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		initialize();
		int res = MAX;
		for(int i=0;i<n-1;++i){
			for(int j=0;j<n-1;++j){
				if(res > getDP(n-1,i,j))	res = getDP(n-1,i,j);
				if(res > getDP(i,n-1,j))	res = getDP(i,n-1,j);
				if(res > getDP(i,j,n-1))	res = getDP(i,j,n-1);
			}
		}
		printf("%d\n",res);
	}
}
