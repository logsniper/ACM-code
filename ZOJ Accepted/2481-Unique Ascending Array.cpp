#include<cstdio>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int N;
	int A[100];
	while(scanf("%d",&N)&&N!=0){
		int i;
		for(i=0;i<N;i++)
			scanf("%d",A+i);
		qsort(A,N,sizeof(int),comp);
		bool space=0;
		int pre=A[0];
		printf("%d",A[0]);
		for(i=1;i<N;i++)
			if(A[i]!=pre){
				printf(" %d",A[i]);
				pre=A[i];
			}
		printf("\n");
	}
	return 0;
}
