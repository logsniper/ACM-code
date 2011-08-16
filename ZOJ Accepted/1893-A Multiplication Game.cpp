#include<cstdio>
#include<cmath>
int main()
{
	unsigned int n;
	while(scanf("%d",&n)!=EOF){
		int a=1;
		while(a<n)	a*=18;
		a/=2;
//		printf("%d %d : ",n,a);
		if(n<=a)	printf("Stan wins.\n");
		else		printf("Ollie wins.\n");
	}
	return 0;
}
