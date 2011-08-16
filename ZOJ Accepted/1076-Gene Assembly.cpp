#include <cstdio>
#include <cstdlib>
#define MAXN 1001
typedef struct gene{
	int s,e,id;
}GENE;
int comp(const void *a,const void *b)
{
	return  ((GENE*)a)->e - ((GENE*)b)->e;
}
GENE item[MAXN];
int dp[MAXN];
int pre[MAXN];
int res[MAXN];
int main()
{
	int n;
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i){
			scanf("%d%d",&item[i].s,&item[i].e);
			item[i].id=i+1;
		}
		qsort(item,n,sizeof(GENE),comp);

		for(int i=0;i<n;++i){
			pre[i]=-1;
			int max=1;
			for(int j=0;j<i;++j){
				if(item[j].e<item[i].s&&dp[j]+1>max){
					max=dp[j]+1;
					pre[i]=j;
				}
			}
			dp[i]=max;
		}
		int max=0,t=0;
		for(int i=0;i<n;++i)
			if(dp[i]>dp[max])	max=i;
		while(dp[max]>1){
//			printf("%d ",item[max].id);
			res[t++]=item[max].id;
			max=pre[max];
		}
//		printf("%d\n",item[max].id);
		res[t++]=item[max].id;
		for(int i=t-1;i>0;--i)
			printf("%d ",res[i]);
		printf("%d\n",res[0]);
	}
	return 0;
}