#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	long long ans;
	while(scanf("%d%d",&n,&k)!=EOF&&!(n==0&&k==0)){
		ans=1;
		int i;
		k=k<(n-k)?k:(n-k);
		for(i=0;i<k;i++){
			ans*=(long long)(n-i);
			ans/=(long long)(i+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
