#include<cstdio>
#include<cstring>
#define MAX(A,B) ((A)>(B)?(A):(B))

int main()
{
	int dp[2001];
	int tmp[2001];
	int n;
	while(scanf("%d",&n)&&n>=0){
		dp[0]=0;
		for(int i=1;i<2001;++i){
			dp[i]=-1;
			tmp[i]=-1;
		}
		int h,totalh=0;
		for(int i=0;i<n;++i){
			scanf("%d",&h);
			totalh+=h;
			memcpy(tmp,dp,(totalh+1)*sizeof(int));
//			for(int j=0;j<=totalh;++j)
//				tmp[j]=dp[j];
			for(int j=0;j<=totalh;++j){
				int a=tmp[j],b=-1,c=-1,d=-1;
				if(h+j<=2000&&tmp[h+j]>=0)
					b=tmp[h+j]+h;
				if(h-j>=0&&tmp[h-j]>=0)
					c=tmp[h-j]+h-j;
				if(j-h>=0&&tmp[j-h]>=0)
					d=tmp[j-h];
				dp[j]=MAX(MAX(a,b),MAX(c,d));
			}
		}
		if(dp[0])
			printf("%d\n",dp[0]);
		else
			printf("Sorry\n");
	}
	return 0;
}
