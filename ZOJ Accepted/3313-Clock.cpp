#include <cstdio>
int main()
{
	int T,x;
	float res;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		res=x*1.0/180*86400;
		printf("%.2f\n",res);
	}
	return 0;
}