#include <cstdio>
#include <cstdlib>
#define MAXN 1000001
int num[MAXN];
int count[241];
int res[MAXN];
void calnum()
{
	for(int i=0;i<MAXN;++i)	num[i]=0;
	for(int i=1;i<MAXN;++i){
		for(int j=i;j<MAXN;j+=i)
			++num[j];
	}
	for(int i=1;i<241;++i)
		count[i]=0;
	for(int i=1;i<MAXN;++i){
		res[i]=count[num[i]];
		++count[num[i]];
	}
}
int main()
{
	calnum();
	int k;
	while(scanf("%d",&k)!=EOF){
		printf("%d\n",res[k]);
	}
	return 0;
}