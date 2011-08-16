#include<cstdio>
using namespace std;
int main()
{
	int n,a,b;
	int k,s;
	while(scanf("%d",&n)!=EOF){
		s=0;
		for(k=1;s<n;k++)
			s+=k;
		s=s-k+1;
		if(k%2==1){
			a=n-s;
			b=k-a;
		}
		else {
			b=n-s;
			a=k-b;
		}
		printf("TERM %d IS %d/%d\n",n,a,b);
	}
	return 0;
}
