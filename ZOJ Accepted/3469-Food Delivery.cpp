#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX (1LL<<60)
#define MAXN 1000
#define ABS(X) ((X)<0?(-(X)):(X))
using namespace std;

struct Place{
	long long x,b;
	bool operator <(const Place &t)const{
		return x<t.x;
	}
}p[MAXN+1];
long long N,V,X;
long long dp[MAXN+1][MAXN+1];
long long sum[MAXN+1];


int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%lld%lld%lld",&N,&V,&X)!=EOF){
		sum[0] = 0;
		for(int i=1;i<=N;++i){
			scanf("%lld%lld",&p[i].x,&p[i].b);
		}
		sort(p+1,p+N+1);
		for(int i=1;i<=N;++i)	sum[i] = sum[i-1]+p[i].b;
		int left=0;
		for(int i=1;i<=N&&p[i].x<=X;++i) left = i;
		dp[1][left] = sum[N]*ABS(p[left].x-X)*V;
		dp[1][left+1] = sum[N]*ABS(p[left+1].x-X)*V;
		for(int c=2;c<=N;++c){
			for(int i=1;i<=N;++i){
				dp[c][i] = MAX;
				//method 1
				if(i<=left-c || i>left+c)	continue;
				int l,r;
				if(i<=left){
					l = i+1;
					r = i+c-1;
					if(r>N)	continue;
					dp[c][i] = dp[c-1][r]+ABS(p[i].x-p[r].x)*V*(sum[N]-sum[r]+sum[i]);
					if(l<=left){
						long long t = dp[c-1][l]+ABS(p[i].x-p[l].x)*V*(sum[N]-sum[r]+sum[i]);
						if(dp[c][i] > t)	dp[c][i] = t;
					}
				}
				else{
					l = i-c+1;
					r = i-1;
					if(l<1)	continue;
					dp[c][i] = dp[c-1][l]+ABS(p[i].x-p[l].x)*V*(sum[N]-sum[r]+sum[l-1]);
					if(r>left){
						long long t = dp[c-1][r]+ABS(p[i].x-p[r].x)*V*(sum[N]-sum[r]+sum[l-1]);
						if(dp[c][i] > t)	dp[c][i] = t;
					}
				}//method 1 end
			}
			//method 2
/*			int l,r;
			l = (left-c>=0)?(left-c+1):1;
			r = (N-c+1<=left)?(N-c+1):left;
//			printf("%d %d\n",l,r);
			for(int i=l;i<=r;++i){
				if(i+c-1>left)
					dp[c][i] = dp[c-1][i+c-1]+ABS(p[i].x-p[i+c-1].x)*V*(sum[N]-sum[i+c-1]+sum[i]);
				if(i!=left){
					long long t = dp[c-1][i+1]+ABS(p[i].x-p[i+1].x)*V*(sum[N]-sum[i+c-1]+sum[i]);
					if(dp[c][i] > t)	dp[c][i] = t;
				}
//				printf("dp[%d][%d] = %lld\n",c,i,dp[c][i]);
			}
			l = (c>left)?c:(left+1);
			r = (c+left<=N)?(c+left):N;
//			printf("%d %d\n",l,r);
			for(int i=l;i<=r;++i){
				if(i-c+1<=left)
					dp[c][i] = dp[c-1][i-c+1]+ABS(p[i].x-p[i-c+1].x)*V*(sum[N]-sum[i-1]+sum[i-c]);
				if(i!=left+1){
					long long t = dp[c-1][i-1]+ABS(p[i].x-p[i-1].x)*V*(sum[N]-sum[i-1]+sum[i-c]);
					if(dp[c][i] > t)	dp[c][i] = t;
				}
//				printf("dp[%d][%d] = %lld\n",c,i,dp[c][i]);
			}//method 2 end
*/
		}
		long long res = dp[N][1]<dp[N][N]?dp[N][1]:dp[N][N];
		printf("%lld\n",res);
	}
	return 0;
}
