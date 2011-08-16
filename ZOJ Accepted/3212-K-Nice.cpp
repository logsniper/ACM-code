#include<cstdio>
int main()
{
	int T,n,m,k;
	int matrix[25][25];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		int i,j;
		int max=(n-2)*(m-2);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				matrix[i][j]=0;
		int p;
		for(p=1;p<=max-k;p++){
			matrix[(p-1)/(m-2)][(p-1)%(m-2)+1]=p;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d",matrix[i][j]);
				if(j<m-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
