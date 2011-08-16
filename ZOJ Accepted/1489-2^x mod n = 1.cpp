#include<cstdio>
using namespace std;

int main()
{
	unsigned long n,x1,x2;
	long tmp;
	long fuck;
	while((scanf("%ld",&n))!=EOF){
		if(n%2==0) printf("2^? mod %ld = 1\n",n);
		else if(n==1) printf("2^? mod 1 = 1\n");
		else {
			for(x1=0,tmp=1;tmp<n;x1++) tmp=tmp<<1;
			tmp=tmp-n;
			for(x2=x1;tmp%n!=1;){
				tmp<<=1;
				x2++;
				if(tmp>n) tmp-=n;
			}
			printf("2^%ld mod %ld = 1\n",x2,n);
		}
	}
	return 0;
}
