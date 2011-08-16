#include <cstdio>
#define MOD 10000007
long long dp[102][52];
long long c[102][102];
long long factorial[102];
void init()
{
	c[0][0]=1;
	for(int i=1;i<=100;++i){
		for(int j=0;j<=i;++j){
			c[i][j]=0;
			if(j<=i-1)	c[i][j]+=c[i-1][j];
			if(j>0)		c[i][j]+=c[i-1][j-1];
			c[i][j]%=MOD;
		}
	}

	factorial[0]=1;
	for(int i=1;i<=100;++i)		factorial[i]=factorial[i-1]*i%MOD;
	
	dp[0][0]=1,dp[1][0]=0,dp[2][0]=1;
	for(int x=3;x<=100;++x){
		dp[x][0]=0;
		for(int i=1;i<=x-1;++i){
			dp[x][0]+=(dp[x-i-1][0]*c[x-1][i]%MOD)*factorial[i]%MOD;
		}
		dp[x][0]%=MOD;
	}
	for(int y=1;y<=50;++y){
		for(int x=0;x<=100-2*y;++x){
			dp[x][y]=0;
			for(int i=0;i<=y;++i)
				dp[x][y]+=c[y][i]*dp[x+y-i][0]%MOD;
			dp[x][y]%=MOD;
		}
	}
}

char mm[100][104];
bool check(int n,int &x,int &y)
{
	int count;
	x=y=0;
	for(int i=0;i<n;++i){
		count=0;
		for(int j=0;j<n;++j)
			if(mm[i][j]=='Y')	++count;
		if(count>1)	return false;//同一行有多于一个Y
	}
	for(int j=0;j<n;++j){
		count=0;
		for(int i=0;i<n;++i){
			if(mm[i][j]=='Y')	++count;
		}
		if(count>1)	return false;//同一列有多于一个Y
	}
	for(int i=0;i<n;++i){
		int count1=0,count2=0;
		for(int j=0;j<n;++j){
			if(mm[i][j]=='Y')	++count1;//i发出的道路数
			if(mm[j][i]=='Y')	++count2;//到达i的道路数
		}
		if(count1==0&&count2==0)	++x;
		if(count1==1&&count2==0)	++y;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	init();
// 	for(int i=0;i<=100;++i){
// 		for(int j=0;j<=i;++j)
// 			printf("%d ",c[i][j]);
// 		printf("\n");
// 	}
	int n,x,y;
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i)	scanf("%s",mm[i]);
		if(check(n,x,y))	printf("%lld\n",dp[x][y]);
		else		printf("0\n");
//		printf("x=%d y=%d\n",x,y);
	}
	return 0;
}