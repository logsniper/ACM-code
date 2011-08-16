#include<cstdio>
long long key[2001][11];
int main()
{
	int T,t;
	int n,m;
	scanf("%d",&T);
	for(t=1;t<=T;++t){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
			key[i][0]=1;
		int p=1;
		for(int k=1;k<n;++k,p*=2){
			int max1=m/(p*2);
			for(int i=1;i<=max1;++i){
				key[i][k]=0;
				int max2=m/p;
				for(int j=i*2;j<=max2;++j)
					key[i][k]+=key[j][k-1];
			}
		}
		long long res=0;
		p=1;
		for(int i=1;i<=n-1;++i)
			p*=2;
		for(int i=1;i<=m/p;++i)
			res+=key[i][n-1];
		printf("Case %d: n = %d, m = %d, # lists = %lld\n",t,n,m,res);
	}
	return 0;
}
