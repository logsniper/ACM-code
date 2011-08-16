 #include<cstdio>
using namespace std;
int ans[301][18];
int dp(int n,int max)
{
	if(ans[n][max]!=-1)	return ans[n][max];
	if(max==1){
		ans[n][1]=1;
		return ans[n][max];
	}
	if(n<max*max){
		ans[n][max]=0;
		return ans[n][max];
	}
	if(n==max*max){
		ans[n][max]=1;
		return ans[n][max];
	}
	
	int key=0;
	for(int i=1;i<=max;i++)
			key+=dp(n-max*max,i);
	ans[n][max]=key;
	return key;
}

int main()
{
	int n,i,j;
	for(i=0;i<301;i++)
		for(j=0;j<18;j++)
			ans[i][j]=-1;
	while(scanf("%d",&n)&&n!=0){
		int key=0;
		for(i=1;i*i<=n;i++)
			key+=dp(n,i);
		printf("%d\n",key);
	}
	return 0;
}
