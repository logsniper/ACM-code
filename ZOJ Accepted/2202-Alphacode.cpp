#include<cstdio>
using namespace std;
#define M 10000
int f[M];

int main()
{
	char num[M];
	int a[M];
	int n,total,i;
	bool flag;
	f[0]=1;f[1]=1;f[2]=2;
	for(i=3;i<M;i++)	f[i]=f[i-1]+f[i-2];
	a[0]=0;
	while(scanf("%c",num)&&num[0]!='0'){
		n=0;
		total=1;
		num[1]=num[0];
		for(i=1;num[i]!='\n';){
			a[i]=num[i]-'0';
			if(a[i]==0){
				n-=1;
				total*=f[n];
				n=0;
			}
			else if(a[i-1]>2||(a[i-1]==2&&a[i]>6)){
				total*=f[n];
				n=1;
			}
			else n++;
			scanf("%c",&num[++i]);
		}
		if(n>0)
			total*=f[n];
		printf("%d\n",total);
	}
	return 0;
}
