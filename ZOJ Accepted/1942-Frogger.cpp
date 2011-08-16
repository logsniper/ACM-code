#include<cstdio>
#include<cmath>
#define MAX(A,B) (A>B?A:B)
double dist[200][200];
int stones[200][2];

void init_dist(int n){
	int i,j;
	for(j=0;j<n;j++){
		scanf("%d%d",&stones[j][0],&stones[j][1]);
		for(i=0;i<=j;i++){
			dist[i][j]=sqrt(
				(stones[i][0]-stones[j][0])*(stones[i][0]-stones[j][0])
				+(stones[i][1]-stones[j][1])*(stones[i][1]-stones[j][1])	);
			dist[j][i]=dist[i][j];
		}
	}
	return;
}

double frog_distance(int n)
{
	int i,j,k;
	for(i=n-1;i>=0;i--)
		for(j=n-1;j>=0;j--){
			if(j==i)	continue;
			for(k=n-1;k>=0;k--){
				if(k==i||k==j)	continue;
				if(dist[i][k]<dist[i][j]&&dist[j][k]<dist[i][j]){
					dist[i][j]=MAX(dist[i][k],dist[j][k]);
					dist[j][i]=dist[i][j];
				}
			}
		}
	return dist[0][1];
}

int main()
{
	int n,i,j,cas=0;;
	while(scanf("%d",&n)!=EOF&&n!=0){
		cas++;
		init_dist(n);
		double FD=frog_distance(n);
/*		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf("%.3lf ",dist[i][j]);
			printf("\n");
		}*/
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cas,FD);
	}
	return 0;
}
