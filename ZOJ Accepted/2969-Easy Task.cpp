#include<cstdio>
int main()
{
	int T,N,c[102];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int k;
		bool zero=true;
		for(k=N;k>=0;k--){
			scanf("%d",&c[k]);
			c[k]=k*c[k];
			if(c[k]!=0)	zero=false;
		}
		if(zero)
			printf("0\n");
		else{
			int i;
			k=N;
			while(c[k]==0)
				--k;
			for(i=k;i>=1;i--){
				printf("%d",c[i]);
				if(i==1)	printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
