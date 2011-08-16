#include<cstdio>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int N,M;
	int i,j;
	int a[10000],b[10000];
	int num;
	while(scanf("%d%d",&N,&M)!=EOF){
		for(i=0;i<N;i++)
			scanf("%d",a+i);
		for(j=0;j<M;j++)
			scanf("%d",b+j);
		qsort(a,N,4,comp);
		qsort(b,M,4,comp);
		num=0;
		for(i=0,j=0;i<N;i++){
			for(;j<M;j++){
//					printf("%d %d\n",a[i],b[j]);
				if(a[i]==b[j]){
					num++;
					j++;
					break;
				}
				else if(a[i]<b[j]){
					break;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
