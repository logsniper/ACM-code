#include <cstdio>
int mat[100][100];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF){
		if(n==2){
			mat[0][0]=0,mat[0][1]=mat[1][0]=1,mat[1][1]=10;
		}
		else{
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)	mat[i][j]=1;
			for(int i=0;i<n-1;++i){
				mat[i][i+1]=0;
				if(i+2<n)	mat[i][i+2]=0;
			}
			mat[n-2][0]=mat[n-1][1]=0;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(j)	printf(" ");
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}