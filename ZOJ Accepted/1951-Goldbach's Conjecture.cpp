#include<cstdio>
#include<cmath>
using namespace std;
bool IsPrime(int n)
{
	if(n<=1)	return 0;
	if(n==2||n==3)	return 1;
	int k=sqrt(n),t;
	for(t=2;t<=k;t++){
		if(n%t==0)	return 0;
	}
	return 1;
}

int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int half=n/2;
		for(a=3;a<=half;a++){
			if(!IsPrime(a))	continue;
			if(!IsPrime(n-a))	continue;
			b=n-a;
			printf("%d = %d + %d\n",n,a,b);
			break;
		}
	}
	return 0;
}
