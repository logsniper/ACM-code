#include<cstdio>
#include<cmath>
int primedivisor[31],pdnum[31],num,ans;

void init(int n,int m)
{
	num=0,ans=0;
	int t=n,k;
	for(k=2;t>1;++k){
		if(t%k==0){
			primedivisor[num]=k;
			pdnum[num]=0;
			++num;
		}
		while(t%k==0){
			++pdnum[num-1];
			t/=k;
		}
	}
	for(k=0;k<num;++k)
		pdnum[k]*=m;
}

bool prime(int n)
{
	if(n==2||n==3)	return true;
	int m=(int)sqrt(n);
	for(int k=2;k<=m;k++)
		if(n%k==0)	return false;
	return true;
}

void dfs(int n,int m,long long nowN,int depth)
{
	if(depth==num&&nowN<=n){
		++ans;
//		printf("<%lld>",nowN);
		return;
	}
	if(nowN>n||depth>=num)	return;
	int multy=primedivisor[depth];
	for(int k=0;k<=pdnum[depth]&&nowN<=n;++k){
		dfs(n,m,nowN,depth+1);
		nowN*=multy;
	}
	return;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==1){
			printf("1\n");
			continue;
		}
		if(prime(n)){
			printf("2\n");
			continue;
		}
		init(n,m);
//		for(int i=0;i<num;++i)
//			printf("%d %d\n",primedivisor[i],pdnum[i]);
		dfs(n,m,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
