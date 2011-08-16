#include<cstdio>
#include<cmath>
bool check(long long n,int p)
{
	if(n<0&&p%2==0)	return false;
	if(n<0)	n=-n;
	double k = pow(n,1.0f/p);
	long long pw = (long long)(k+0.5);
	long long a=1;
	for(int i=0;i<p;++i)
		a *= pw;
//	printf("%lf %lld %lld\n",k,pw,a);
	if(a==n)	return true;
	return false;
}
int main()
{
//	freopen("input.txt","r",stdin);
	long long n;
	int p;
	while(scanf("%lld",&n)!=EOF&&n!=0){
		if(n==1){
			printf("1\n");
			continue;
		}
//		scanf("%d",&p);
		for(p=32;p>1&&!check(n,p);--p);
		printf("%d\n",p);
	}
	return 0;
}
