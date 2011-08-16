#include<cstdio>
int grid[100][100],maxnum[100][100];
int n,k,ans;

int dp(int x,int y)
{
	if(maxnum[x][y]!=-1)
		return maxnum[x][y];
	int max=0,t;
	for(t=-k;t<=k;t++){
		if(x+t>=0&&x+t<n)
			if(grid[x+t][y]<grid[x][y]&&dp(x+t,y)>max){
				max=dp(x+t,y);
			}
		if(y+t>=0&&y+t<n)
			if(grid[x][y+t]<grid[x][y]&&dp(x,y+t)>max){
				max=dp(x,y+t);
			}
	}
	if(max>0)
		maxnum[x][y]=max+grid[x][y];
	else maxnum[x][y]=0;
	return maxnum[x][y];
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF&&!(n==-1&&k==-1)){
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				scanf("%d",&grid[i][j]);
				maxnum[i][j]=-1;
			}
		maxnum[0][0]=grid[0][0];
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(dp(i,j)>ans)	ans=dp(i,j);
/*		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf("%d ",maxnum[i][j]);
			printf("\n");
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
