#include <cstdio>
#include <cstring>
bool mat[101][101];
bool visited[101];
int seq[100],p;
int n;

void cal()
{
	for(int i=1;i<=n;++i){
		seq[0]=i;p=1;visited[i]=true;
		int head=i;
		while(p<n){
			int max=-1,maxk;
			for(int k=1;k<=n;++k){
				if(!mat[head][k] || visited[k])	continue;
				int count=0;
				for(int j=1;j<=n;++j)
					if(mat[k][j]&&!visited[j])
						++count;
				if(count>max){
					max=count,maxk=k;
				}
			}
			if(max==-1)	break;
			seq[p++]=maxk;
			visited[maxk]=true;
			head=maxk;
		}
		if(p==n)	break;
		visited[i]=false;
	}
}

int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		memset(mat,0,sizeof(mat));
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		int way=n*(n-1)/2;
		while(way--){
			scanf("%d%d",&a,&b);
			mat[a][b]=true;
		}
		cal();
		if(p<n)	printf("Impossible\n");
		else{
			for(int i=0;i<n;++i){
				if(i!=0)	printf(" ");
				printf("%d",seq[i]);
			}
			printf("\n");
		}
	}
}