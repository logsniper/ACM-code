#include<cstdio>
using namespace std;

int main()
{
	int A;
	int i;
	while(scanf("%d",&A)&&A!=0){
		for(i=1;A%i==0;i*=2);
		i/=2;
		printf("%d\n",i);
	}
}
