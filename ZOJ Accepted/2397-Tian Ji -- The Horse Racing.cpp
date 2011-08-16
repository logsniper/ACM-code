#include<cstdio>
#include<algorithm>
using namespace std;
#define UNSOLVED 100000
int tianji[1000],king[1000];
int solve[1000][1000];
int findkey(int n,int i,int j)
{
	int ret;
	if (solve[i][j]!=UNSOLVED)	return solve[i][j];
	if(i==n-1){
		ret = -(n-1-j);
		if(tianji[i]<king[j])	--ret;
		else if(tianji[i]>king[j])	++ret;
	}
	else{
		if(tianji[i]<king[j])
			ret = findkey(n,i+1,j);
		else if(tianji[i]>king[j])
			ret = findkey(n,i+1,j+1) +1;
		else{
			int a = findkey(n,i+1,j);
			int b = findkey(n,i+1,j+1);
			ret = a>b?a:b;
		}
	}
//	printf("(%d,%d) : %d\n",i,j,ret);
	solve[i][j]=ret;
	return solve[i][j];
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				solve[i][j]=UNSOLVED;
		for(int i=0;i<n;++i)
			scanf("%d",&tianji[i]);
		for(int j=0;j<n;++j)
			scanf("%d",&king[j]);
		sort(tianji,tianji+n);
		sort(king,king+n);
		int res = findkey(n,0,0)*200;
		printf("%d\n",res);
	}
	return 0;
}
