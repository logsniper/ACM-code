#include<cstdio>
#include<cmath>
int main()
{
	int z,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		z=0;
		double log5 = log(5);
		int max = int(log(n)/log5);
		int m=5;
		for(int k=0;k<max;++k){
			z+=n/m;
			m*=5;
		}
		printf("%d\n",z);
	}
	return 0;
}
