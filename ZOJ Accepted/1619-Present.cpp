#include<cstdio>

double pre[101];

void init()
{
	int k;
	pre[0]=1.0;
	for(k=1;k<=100;++k)
		pre[k]=pre[k-1]/k;
	return ;
}

int main()
{
	init();
	double ans;
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF){
		ans=1.0;
		int k=N-M,i;
		for(i=1;i<=k;++i){
			if(i%2)	ans-=pre[i];
			else ans+=pre[i];
		}
		ans*=(double)pre[M];
		printf("%.8lf\n",ans);
	}
	return 0;
}
