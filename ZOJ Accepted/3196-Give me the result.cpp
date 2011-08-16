#include<cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int num[9];
long long ans;

bool check(long long num,int k)
{
	if(num==k)	return false;
	while(num>=1){
		int t=num%10;
		if(t==k)	return false;
		num/=10;
	}
	return true;
}

void dfs(int num[],int n,long long numpre,int depth,int k)
{
//	printf("%d : %d ",depth,numpre);
	long long a[4];
	int i,p=3;
	a[0]=numpre*num[depth],a[1]=numpre+num[depth],a[2]=fabs(1.0*(numpre-num[depth]));
	if(num[depth]>0){a[3]=numpre/num[depth];p=4;}
//	printf("%d %d %d\n",a[0],a[1],a[2]);
	if(depth==n-1){
		for(i=0;i<p;i++)
			if(check(a[i],k)&&a[i]>ans){	ans=a[i];	}
		return ;
	}
	for(i=0;i<p;i++)
		dfs(num,n,a[i],depth+1,k);
	return;
}

int main()
{
	int T,n, k;
	scanf("%d",&T);
	while(T--){
		ans=-1;
		scanf("%d%d",&n,&k);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		
		dfs(num,n,num[0],1,k);
		if(ans!=-1)
			printf("%lld\n",ans);
		else
			printf("No result\n");
	}
	return 0;
}
