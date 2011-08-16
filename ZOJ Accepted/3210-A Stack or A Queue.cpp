#include<cstdio>
int main()
{
	int T,N,i;
	int a[100],b[100];
	scanf("%d",&T);
	while(T--){
		bool stack=true,queue=true;
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		for(i=0;i<N;i++){
			scanf("%d",&b[i]);
			if(b[i]!=a[i])
				queue=false;
			if(b[i]!=a[N-i-1])
				stack=false;
		}
		if(queue&&stack)
			printf("both\n");
		else if(queue&&!stack)
			printf("queue\n");
		else if(!queue&&stack)
			printf("stack\n");
		else
			printf("neither\n");
	}
	return 0;
}
