#include<cstdio>
#include<cstdlib>
#define MAXN 2147483647
int ans[50000],total;
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	total=0;
	int k;
	long long tmp;
	for(k=2;k<=46340;k++){
		tmp=k*k;
		while(tmp<=MAXN){
			ans[total++]=tmp;
			tmp*=k;
		}
	}
	qsort(ans,total,sizeof(int),comp);
	int prev=0;
	for(k=0;k<total;k++){
		while(ans[k]==prev)	k++;
		printf("%d\n",ans[k]);
		prev=ans[k];
	}
	return 0;
}
