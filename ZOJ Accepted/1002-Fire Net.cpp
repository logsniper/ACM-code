#include<cstdio>
char city[4][4];
int max;
int t;

bool checkline(int n,int i,int j)
{
	int k,t;
	bool legal=true;
	for(k=0;k<i;k++)
		if(city[k][j]=='O'){
			legal=false;
			for(t=k+1;t<i;t++)
				if(city[t][j]=='X')	legal=true;
			if(legal==false)	return false;
		}
	for(k=0;k<j;k++)
		if(city[i][k]=='O'){
			legal=false;
			for(t=k+1;t<j;t++)
				if(city[i][t]=='X')	legal=true;
			if(legal==false)	return false;
		}
	return true;
}

int getnum(int n)
{
	int i,j,num=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(city[i][j]=='O')
				num++;
	return num;
}

void dfs(int n,int empty,int depth,char type)
{
	int k,i,j;
	for(i=0,k=1;k<depth||city[i/n][i%n]=='X';i++){
		if(city[i/n][i%n]!='X')	k++;
	}
	city[i/n][i%n]=type;
	if(city[i/n][i%n]=='O'&&checkline(n,i/n,i%n)==false)	return;

	if(depth==empty){
		if(getnum(n)>max)
			max=getnum(n);
		return;
	}
	else{
		char fire;
		fire='O';	dfs(n,empty,depth+1,fire);
		fire='.';	dfs(n,empty,depth+1,fire);
	}
}

int main()
{
	int n;
//	freopen("input.txt","r",stdin);

	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j,empty=0;
		max=0;
		for(i=0;i<n;i++){
			scanf("%s",city[i]);
			for(j=0;j<n;j++)
				if(city[i][j]!='X')	empty++;
		}
		if(empty==0){
			printf("0\n");
			continue;
		}
		char fire;
		fire='O';	dfs(n,empty,1,fire);
		fire='.';	dfs(n,empty,1,fire);
		printf("%d\n",max);
	}
	
	return 0;
}
