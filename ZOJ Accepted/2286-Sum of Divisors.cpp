#include<cstdio>
#include<cstdlib>
int f[1000001];
void init()
{
	int k,p;
	f[0]=0;
	for(k=1;k<=1000000;++k)
		f[k]=1;
	for(k=2;k<=1000000;++k)
		for(p=k+k;p<=1000000;p+=k)
			f[p]+=k;
}
int main()
{
	init();
	int m;
	while(scanf("%d",&m)!=EOF){
		int res=0;
		for(int i=1;i<=1000000;++i)
			if(f[i]<=m)	++res;
		printf("%d\n",res);
	}
	return 0;
}
