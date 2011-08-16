#include<cstdio>
#include<cstring>
#define MIN (1<<31)
int bonus[1000];
int dp[2][100];
int post[10001][100];
int n,m;
char res[10004];
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n)!= EOF){
		//input
		memset(bonus,0,sizeof bonus);
		memset(dp,0,sizeof dp);
		memset(post,0,sizeof post);
		for(int i=0;i<m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			bonus[a] = b;
		}
		if(n<3){
			while(n--)	printf("0");
			printf("\n");
			continue;
		}
		//initialize
		for(int i=0;i<100;++i){
			dp[0][i]=MIN;
			for(int j=0;j<10;++j){
				if(dp[0][i] < bonus[i*10+j]){
					dp[0][i] = bonus[i*10+j];
					post[3][i] = j;
				}
			}
			if(dp[0][i] == MIN){
				dp[0][i] = 0;
				post[3][i] = 0;
			}
		}
		//dp
		for(int len=4;len<=n;++len){
			for(int i=0;i<100;++i){
				dp[1][i] = MIN;
			}
			for(int i=0;i<100;++i){
				for(int j=0;j<10;++j){
					if(dp[1][i] < dp[0][(i*10+j)%100]+bonus[i*10+j]){
						dp[1][i] = dp[0][(i*10+j)%100]+bonus[i*10+j];
						post[len][i] = j;
					}
				}
			}
			memcpy(dp[0],dp[1],sizeof dp[1]);
		}
		//get result
		int max = MIN,num=0;
		for(int i=0;i<100;++i){
			if(max < dp[0][i]){
				max = dp[0][i];
				num = i;
			}
		}
		//output
		memset(res,0,sizeof res);
		res[0] = '0'+num/10;
		res[1] = '0'+num%10;
		for(int len=n;len>=3;--len){
			int p = (res[n-len]-'0')*10 + res[n-len+1]-'0';
			res[n-len+2] = post[len][p]+'0';
		}
		printf("%s\n",res);
	}
	return 0;
}
