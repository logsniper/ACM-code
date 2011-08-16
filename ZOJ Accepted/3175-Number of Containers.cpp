#include <cstdio>
#include <cmath>
int main()
{
	int test;
	int n,xxx,kkk;
	long long res;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		xxx=int((sqrt((double)4*n+1)+1)/2);
		kkk=n/xxx;
		res=0;
		for(int i=1;i<xxx;++i)
			res+=n/i;
		for(int i=1;i<=kkk;++i)
			res+=(int(n/i)-int(n/(i+1)))*i;
		res-=n;
		printf("%lld\n",res);
	}
	return 0;
}