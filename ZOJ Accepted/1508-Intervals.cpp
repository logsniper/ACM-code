#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct{
	int ai,bi,ci;
}Interval;
int n;

Interval itv[50000];
bool flag[50001];

int comp(const void *a,const void *b)
{
	int key;
	key = ((Interval*)a)->bi - ((Interval*)b)->bi;
	if(key == 0)
		key = ((Interval*)a)->ai - ((Interval*)b)->ai;
	if(key == 0)
		key = ((Interval*)b)->ci - ((Interval*)a)->ci;
	return key;
}

void gen(int k)
{
	int need=itv[k].ci;
	for(int i=itv[k].ai;i<=itv[k].bi;++i)
		if(flag[i])	--need;
	int p=itv[k].bi;
	while(need>0){
		if(flag[p])	--p;
		else{
			flag[p]=true;
			--need,--p;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int ans;
	while(scanf("%d",&n)!=EOF){

		for(int i=0;i<n;++i)
			scanf("%d%d%d",&itv[i].ai,&itv[i].bi,&itv[i].ci);
		qsort(itv,n,sizeof(Interval),comp);
		memset(flag,0,50001);

		for(int i=0;i<n;++i){
			gen(i);
		}

		ans=0;
		for(int i=0;i<50001;++i){
			if(flag[i])	++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
