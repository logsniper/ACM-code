#include<cstdio>
#include<math.h>
using namespace std;
int N[78500];
int IsPrime(int n)
{
	if(n==0)	return 0;
	int k=(int)sqrt(n);
	int i;
	for(i=0;N[i]<=k;i++)
		if(n%N[i]==0)	return 0;
	return 1;
}

int main()
{
	int n,i,k,left;
	N[0]=2;N[1]=3;
	for(n=5,i=2;n<=1000000;n++){
		if(IsPrime(n))	N[i++]=n;
	}
	while(scanf("%d",&n)!=EOF){
		k=(int)sqrt(n);
		left =0;
		for(i=0;N[i]<=k;i++){
			if(n%N[i]==0)	{left=n/N[i];break;}
		}
		if(IsPrime(left))	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
