#include<cstdio>
#include<cstdlib>
using namespace std;
typedef	struct{
	int value;
	int weight;
}COIN;
int fc[10000];
bool flag;
int comp(const void *a,const void *b)
{
	return (*(COIN*)a).weight-(*(COIN*)b).weight;
}
int fill(COIN a[],int n,int contain)
{
	if(fc[contain]!=-2)	return fc[contain];
	if(contain==0){
		flag=1;
		fc[contain]=0;
		return 0;
	}
	if(contain<a[0].weight){
		fc[contain]=-1;
		return -1;
	}
	int i,min_amout=500000000;
	for(i=0;i<n&&a[i].weight<=contain;i++){
		int tmp_amount=a[i].value;
		int tmp=fill(a,n,contain-a[i].weight);
		if(tmp>0)	tmp_amount+=tmp;
		if(tmp_amount<min_amout&&tmp>=0)	min_amout=tmp_amount;
	}
	if(min_amout<500000000&&flag){
		fc[contain]=min_amout;
		return min_amout;
	}
	fc[contain]=-1;
	return -1;
}
int main()
{
	COIN cn[501];
	int T,E,F,N,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&E,&F,&N);
		for(i=0;i<=F-E;i++)
			fc[i]=-2;
		for(i=0;i<N;i++)
			scanf("%d%d",&cn[i].value,&cn[i].weight);
		qsort(cn,N,sizeof(COIN),comp);
		flag=0;
		int ans=fill(cn,N,F-E);
		if(ans>0)	printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
		else printf("This is impossible.\n");
	}
	return 0;
}
