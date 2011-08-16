#include<cstdio>
#include<math.h>
using namespace std;

int main()
{
	int N,ans;
	long long k;
	double nln;
	while(scanf("%ld",&N)!=EOF){
		nln=(double)N*log10(N);
		k=(long long)nln;
		ans=(int)pow(10,nln-k);
		printf("%ld\n",ans);
	}
	return 0;
}
