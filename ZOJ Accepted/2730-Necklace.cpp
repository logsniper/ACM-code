#include <cstdio>
#include <cstring>
bool mat[50][50];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF){
		memset(mat ,true, sizeof(mat));
		for(int i=0;i<n;++i)
			mat[i][i]=false;
		int res=n*(n-1)/2;
		printf("%d\n",res);
		int k=0;
		while(res--){
			printf("%d",k);
			int cnt=0;
			int max=0,maxk;
			for(int i=0;i<n;++i){
				if(mat[k][i]){
					for(int j=0;j<n;++j)	if(mat[i][j])	++cnt;
				}
				if(max<cnt){
					max=cnt;
					maxk=i;
				}
			}
			mat[k][maxk]=false;
			mat[maxk][k]=false;
			k=maxk;
			if(res)	printf(" ");
// 			for(int i=0;i<n;++i){
// 				for(int j=0;j<n;++j)
// 					printf("%d ",mat[i][j]);
// 				printf("\n");
// 			}
		}
		putchar('\n');
	}
	return 0;
}