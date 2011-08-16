#include<cstdio>
#define TOTAL 1001
int main()
{
	int a[TOTAL],f[TOTAL],b[TOTAL],n,N;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&n);
		int i,j,max;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++){
			max=0;
			for(j=0;j<i;j++)
				if(a[j]<a[i]&&f[j]>max){
					max=f[j];
					b[i]=j;
				}
			f[i]=max+1;
		}
		int last;
		for(i=0,max=0;i<n;i++)
			if(f[i]>max){
				max=f[i];
				last=i;
			}
		printf("%d\n",max);
/*
		//数组b[]记录该子列的每一项 
		int k=last;
		while(max--){
			printf("%d ",a[k]);
			k=b[k];
		}*/
		if(N)	printf("\n");
	}
	return 0;
}
