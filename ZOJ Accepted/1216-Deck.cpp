#include<cstdio>
using namespace std;

int main()
{
	int n,i,k=0;
	double length,tmp;
	bool IsTitle=1;
	while(scanf("%d",&n)!=EOF){
		length=0;
		for(i=1;i<=n;i++){
			length+=(double)1/(2*i);
		}
		if(IsTitle){
			printf("# Cards  Overhang\n");
			IsTitle=0;
		}
		for(tmp=n,k=0;tmp>=1;tmp/=(double)10,k++);
		for(i=1;i<=5-k;i++)	printf(" ");
		printf("%d     ",n);
		printf("%.3f\n",length);
	}
	return 0;
}
