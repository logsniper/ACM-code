#include<cstdio>
using namespace std;
int square[]={9,3,12,6,5,10,11,13,14,7,15};
char farm[50][52];
int part[50][50];
int m,n;
void dfs(int i,int j,int partnum)
{
	if(i<0||i>=m||j<0||j>=n)	return;
	if(!part[i][j]){
		part[i][j]=partnum;
		int type=square[farm[i][j]-'A'];
		if((type&1)&&(square[farm[i-1][j]-'A']&4))
			dfs(i-1,j,partnum);
		if((type&2)&&(square[farm[i][j+1]-'A']&8))
			dfs(i,j+1,partnum);
		if((type&4)&&(square[farm[i+1][j]-'A']&1))
			dfs(i+1,j,partnum);
		if((type&8)&&(square[farm[i][j-1]-'A']&2))
			dfs(i,j-1,partnum);
	}
}
int main()
{
	int partnum;
	while(scanf("%d%d",&m,&n)&&m>0&&n>0){
		for(int i=0;i<m;++i)
			scanf("%s",farm[i]);
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				part[i][j]=0;
		partnum=0;
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(!part[i][j])
					dfs(i,j,++partnum);
		printf("%d\n",partnum);
/*		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j)
				printf("%d ",part[i][j]);
			printf("\n");
		}*/
	}
	return 0;
}
