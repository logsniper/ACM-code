#include<cstdio>
using namespace std;
char square[104][104];
int n;

int WR(int x,int y)
{
	int ans=0,i,j,ymax=n;
	for(i=0;square[y][x+i]=='.'&&x+i<n;i++){
		for(j=0;square[y+j][x+i]=='.'&&y+j<ymax;j++)
			ans++;
		ymax=y+j;
	}
	return ans;
}

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(j=0;j<n;j++)
			scanf("%s",square[j]);
		int ans=0;
		for(j=0;j<n;j++)
			for(i=0;i<n;i++){
				if(square[j][i]=='#')	continue;
				ans+=WR(i,j);
			}
		printf("%d\n",ans);
	}
	return 0;
}
