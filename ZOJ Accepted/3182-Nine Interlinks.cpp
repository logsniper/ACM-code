#include<cstdio>
int main()
{
	int a[32],i,T;
	a[1]=1,a[2]=2;
	for(i=3;i<=30;i++)	a[i]=a[i-1]+2*a[i-2]+1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
