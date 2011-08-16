#include<cstdio>
int numbers[100];//number[i]记录模k余i的数的个数 
bool achieve[100][100];

int main()
{
//	freopen("input.txt","r",stdin);
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		int i,j,t;
		scanf("%d%d",&n,&k);
		for(t=0;t<k;t++)	numbers[t]=0;
		for(i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			tmp=tmp%k;
			while(tmp<0)	tmp+=k;
			++numbers[tmp];
		}
		for(t=0;t<k;t++)	achieve[0][t]=false;
		achieve[0][0]=true;
		for(i=1;i<k;i++){
			for(t=0;t<k;t++)	achieve[i][t]=false;
			if(numbers[i]==0)
				for(t=0;t<k;t++)
					achieve[i][t]=achieve[i-1][t];
			for(j=0;j<=numbers[i];j++){
				int plus=j*i-(numbers[i]-j)*i;
				for(t=0;t<k;t++){
					if(achieve[i-1][t]){
						int now=(t+plus)%k;
						while(now<0)	now+=k;
						achieve[i][now]=true;
					}
				}
			}
		}
/*		for(i=0;i<k;i++){
			for(j=0;j<k;j++)
				printf("%d ",achieve[i][j]);
			printf("\n");
		}*/
		if(achieve[k-1][0])
			printf("Divisible\n");
		else
			printf("Not divisible\n");
			
		if(T)	printf("\n");
	}
	return 0;
}
