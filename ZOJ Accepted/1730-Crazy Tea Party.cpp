#include<cstdio>
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int res;
		if(n%2)
			res=(n-1)*(n-1)/4;
		else
			res=(n/2-1)*n/2;
		printf("%d\n",res);
	}
	return 0;
}
