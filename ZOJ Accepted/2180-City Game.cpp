#include <cstdio>
#define MAXN 1001
int  height[MAXN],prev[MAXN],next[MAXN];
int main()
{
	int k,n,m;
	char tmp[4];
	scanf("%d",&k);
	while(k--){
		scanf("%d%d",&n,&m);
		int res=0;
		for(int j=0;j<m;++j)
			height[j]=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%s",tmp);
				if(tmp[0]=='R')		height[j]=0;
				else		++height[j];
				prev[j]=j;next[j]=j;
			}
			for(int j=0;j<m;++j){
				if(height[j]==0)		continue;
				while(prev[j]>0&&height[prev[j]-1]>=height[j])	prev[j]=prev[prev[j]-1];
			}
			for(int j=m-1;j>=0;--j){
				if(height[j]==0)		continue;
				while(next[j]<m-1&&height[next[j]+1]>=height[j])	next[j]=next[next[j]+1];
			}
			for(int j=0;j<m;++j){
				if(height[j]*(next[j]-prev[j]+1) > res)	res = height[j]*(next[j]-prev[j]+1);
			}
// 			printf("\n");
// 			for(int j=0;j<m;++j)	printf("%d ",height[j]);
// 			printf("\n");
// 			for(int j=0;j<m;++j)	printf("%d ",prev[j]);
// 			printf("\n");
// 			for(int j=0;j<m;++j)	printf("%d ",next[j]);
// 			printf("\n");
		}
		printf("%d\n",res*3);
	}
	return 0;
}