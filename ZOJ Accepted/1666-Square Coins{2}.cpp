#include<cstdio>
int method[300][18];

void init()
{
	int k,p,q;
	for(k=0;k<18;++k)
		method[0][k]=1;
	for(k=1;k<300;++k){
		method[k][0]=0;
		method[k][1]=1;
		for(p=2;p*p<=k;++p){
			if(k==p*p){
				method[k][p]=1;
				continue;
			}
			method[k][p]=0;
			for(q=1;q*q<k&&q<=p;++q)
				method[k][p]+=method[k-p*p][q];
		}
		for(;p<=17;++p)
			method[k][p]=0;
	}
	
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF&&n>0){
		int ans=0;
		for(int i=1;i<18;++i){
//			printf("%d ",method[n][i]);
			ans+=method[n][i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
