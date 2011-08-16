#include<cstdio>
char farm[8][8];
int m,n;
bool dfs(int i,int j,int depth,int tgt_depth)
{
	if(depth >= tgt_depth)
		return true;
	farm[i][j]='v';
	bool ret=false;
	if(!ret&&i<m-1&&farm[i+1][j]=='.')
		ret = dfs(i+1,j,depth+1,tgt_depth);
	if(!ret&&j<n-1&&farm[i][j+1]=='.')
		ret = dfs(i,j+1,depth+1,tgt_depth);
	if(!ret&&i>0&&farm[i-1][j]=='.')
		ret = dfs(i-1,j,depth+1,tgt_depth);
	if(!ret&&j>0&&farm[i][j-1]=='.')
		ret = dfs(i,j-1,depth+1,tgt_depth);
	farm[i][j]='.';
	return ret;
}
int main()
{
	while(scanf("%d%d",&m,&n)!=EOF&&n*m>0){
		int seed = m*n;
		for(int i=0;i<m;++i){
			scanf("%s",farm[i]);
			for(int j=0;j<n;++j)
				if(farm[i][j]!='.')
					--seed;
		}
		bool res;
		if(farm[0][0]=='.')
			res = dfs(0,0,1,seed);
		else
			res = dfs(0,0,0,seed);
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
