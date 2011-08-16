#include<cstdio>
using namespace std;
int c[21][21];
int findway(int begin,int finish)
{
	int i,j;
	bool s[21],tmp[21];
	int ans=0;
	for(i=0;i<21;i++){s[i]=false;tmp[i]=false;}
	s[begin]=true;
	while(1){
		for(i=1;i<=20;i++){
			if(s[i]){
				for(j=1;j<=20;j++){
					if(i!=j&&s[j]==false&&c[i][j]==1){
						tmp[j]=true;
//						printf("%d ",j);
					}
				}
//				printf(": %d\n",ans);
			}
		}
		for(i=0;i<21;i++){
			if(tmp[i]==true){
				s[i]=true;
				tmp[i]=false;
			}
		}
		ans++;
		if(s[finish]==true)	return ans;
	}
}
int main()
{
	int i,j,n;
	int a[21][21];
	int begin,finish;
	int TestSet=0;
	int ans;
	bool Title;
	while(scanf("%d",&a[1][0])!=EOF){
		Title=1;
		TestSet++;
		for(i=0;i<21;i++)
			for(j=0;j<21;j++)
				c[i][j]=0;
		for(i=1;i<=a[1][0];i++){
			scanf("%d",&a[1][i]);
			c[1][a[1][i]]=1;
			c[a[1][i]][1]=1;
		}
		for(i=2;i<=19;i++){
			scanf("%d",&a[i][0]);
			for(j=1;j<=a[i][0];j++){
				scanf("%d",&a[i][j]);
				c[i][a[i][j]]=1;
				c[a[i][j]][i]=1;
			}
		}
		scanf("%d",&n);
		while(n--){
			if(Title){
				printf("Test Set #%d\n",TestSet);
				Title=0;
			}
			scanf("%d%d",&begin,&finish);
			ans=findway(begin,finish);
			printf("%d to %d: %d\n",begin,finish,ans);
		}
		printf("\n");
	}
	return 0;
}
