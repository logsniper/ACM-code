#include<cstdio>
#define MAXN 88
long long b[MAXN];
char base[10]="T.T^__^";

void init()
{
	b[0]=3,b[1]=7;
	for(int i=2;i<MAXN;++i){
		b[i]=b[i-1]+b[i-2];
//		printf("%lld ",b[i]);
	}
	return ;
}

char cal(long long n)
{
	if(n<=7)	return base[n-1];
	int i;
	for(i=MAXN-1;b[i]>=n&&i>=0;--i);
	return cal(n-b[i]);
}

int main()
{
	init();
	long long n;
	while(scanf("%lld",&n)!=EOF){
		char ans = cal(n);
		printf("%c\n",ans);
	}
	return 0;
}