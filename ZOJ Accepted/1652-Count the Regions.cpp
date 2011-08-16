#include<cstdio>
int ans[10001];

void cal()
{
	ans[0]=1,ans[1]=2;
	for(int i=2;i<=10000;++i)
		ans[i]=ans[i-1]+9*i-8;
}

int main()
{
	int n;
	cal();
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",ans[n]);
	}
	return 0;
}
