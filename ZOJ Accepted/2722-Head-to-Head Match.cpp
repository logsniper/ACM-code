#include<cstdio>
using namespace std;
int main()
{
	unsigned int n;
	int k;
	while(scanf("%d",&n)&&n!=0){
		for(k=0;n>1;k++){
			if(n%2)	n=n/2+1;
			else n=n/2;
		}
		printf("%d\n",k);
	}
	return 0;
}
