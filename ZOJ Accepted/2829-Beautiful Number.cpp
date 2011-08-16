#include<cstdio>
using namespace std;
int main()
{
	int BN[100001];
	int i,n;
	BN[0]=0;
	for(n=1,i=3;n<=100000;i++)
		if(i%3==0||i%5==0)
			BN[n++]=i;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",BN[n]);
	}
	return 0;
}
