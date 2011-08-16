#include<cstdio>
#include<math.h>
using namespace std;

int X[729][729],n;
void fill(int n,int x,int y)
{
	int k;
	if(n>0&&n<=7){
		if(n==1) X[x][y]=1;
		else{
			k=(int)pow(3,n-2);
			fill(n-1,x,y);
			fill(n-1,x+k*2,y);
			fill(n-1,x+k,y+k);
			fill(n-1,x,y+k*2);
			fill(n-1,x+k*2,y+k*2);
		}
	}
}

int main()
{
	int i,j,k,nl,flag;
	for(i=0;i<729;i++)
		for(j=0;j<729;j++)
			X[i][j]=0;
	fill(7,0,0);
	while(scanf("%d",&n)&&n!=-1){
		k=(int)pow(3,n-1);
		for(i=0;i<k;i++){
			for(j=0;j<k;j++){
				flag=1;
				for(nl=j+1;nl<k;nl++)
					if(X[i][nl]==1){
						flag=0;
						break;
					}
				if(X[i][j]==1){
					printf("X");
					if(flag){
						printf("\n");
						j=k;
					}
				}
				else	printf(" ");		
			}
		}
		printf("-\n");
	}
	return 0;
}
