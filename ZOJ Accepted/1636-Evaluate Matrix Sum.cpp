#include<cstdio>
int square[51];
int matrix[501][501];
int sum[501][501];
int n,m;

void init1()
{
	for(int k=0;k<51;++k)
		square[k]=k*k;
}

void init2()
{
	int i,j,k;
	for(j=0;j<=n;++j)
		sum[0][j]=0;
	for(i=1;i<=m;++i){
		sum[i][0]=0;
		for(j=1;j<=n;++j){
			scanf("%d",&k);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+square[k];;
		}
	}
}

void query()
{
	int up,left,down,right;
	scanf("%d%d%d%d",&up,&left,&down,&right);
	int ans=sum[down][right]-sum[up-1][right]-sum[down][left-1]+sum[up-1][left-1];
	printf("%d\n",ans);
}

int main()
{
	init1();
	int T,t,N,q;
	scanf("%d",&T);
	for(t=1;t<=T;++t){
		scanf("%d%d",&m,&n);
		init2();
		scanf("%d",&N);
		printf("Case %d:\n",t);
		for(q=0;q<N;++q)
			query();
	}
	return 0;
}
