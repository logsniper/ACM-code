#include<cstdio>
#include<cstring>
char necklace[20004];
int a[10004],b[10004];

int bfs(int n,int length,int depth)
{
	if(n==1||depth==length)	return a[0];
	int i,m=0;
	char min='z';
	for(i=0;i<n;i++)
		if(necklace[a[i]+depth]<min)	min=necklace[a[i]+depth];
//	printf("<%c>",min);
	for(i=0,m=0;i<n;i++)
		if(necklace[a[i]+depth]==min){
			b[m]=a[i];
			++m;
		}
	for(i=0;i<m;i++)
		a[i]=b[i];
//		printf("<%d %d>",n,m);
	n=m;
	return bfs(n,length,depth+1);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",necklace);
		int len=strlen(necklace),ans;
		char tmp[10004];
		strcpy(tmp,necklace);
		strcat(necklace,tmp);
		bool AllSame=true;
		for(int i=0;i<len;i++){
			a[i]=i;
			if(necklace[i]!=necklace[0])
				AllSame=false;
		}
		if(AllSame)	ans=1;
		else ans=bfs(len,len,0)+1;
		printf("%d\n",ans);
	}
	return 0;
}
