#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<29)
#define OFFSET 405
#define DISTANCE(A,B) ((A)<(B)?((B)-(A)):((A)-(B)))

int n,m;
int d[201],p[201];
int dp[2][201][OFFSET*2];
int prev[21][201][OFFSET*2];
void initialize(){
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i],&d[i]);
	}
}

void getDP(){
	for(int i=0;i<=n;++i){
		for(int diff=-20*m;diff<=20*m;++diff){
			if(i==0){
				dp[0][i][diff+OFFSET] = -1;
				prev[1][i][diff+OFFSET] = -1;
			}
			else{
				dp[0][i][diff+OFFSET] = dp[0][i-1][diff+OFFSET];
				prev[1][i][diff+OFFSET] = prev[1][i-1][diff+OFFSET];
			}
		}
		if(i>0){
			int diff = p[i]-d[i], sum = p[i]+d[i];
			if(sum > dp[0][i-1][diff+OFFSET]){
				dp[0][i][diff+OFFSET] = sum;				
				prev[1][i][diff+OFFSET] = i;
			}
		}
	}
	for(int mi=2;mi<=m;++mi){
		for(int j=mi;j<=n;++j){
			for(int diff=-20*m;diff<=20*m;++diff){
				if(j>mi){
					dp[1][j][diff+OFFSET] = dp[1][j-1][diff+OFFSET];
					prev[mi][j][diff+OFFSET] = prev[mi][j-1][diff+OFFSET];
				}
				else{
					dp[1][j][diff+OFFSET] = -1;
					prev[mi][j][diff+OFFSET] = -1;
				}
				if(diff+d[j]-p[j]<-20*m || diff+d[j]-p[j]>20*m)	continue;
				int tmp = dp[0][j-1][diff+d[j]-p[j]+OFFSET]+d[j]+p[j];
				if(dp[0][j-1][diff+d[j]-p[j]+OFFSET] >=0 && dp[1][j][diff+OFFSET] < tmp){
					dp[1][j][diff+OFFSET] = tmp;
					prev[mi][j][diff+OFFSET] = j;
				}
			}
		}
		memcpy(dp[0],dp[1],sizeof dp[1]);
	}
}

void print(){
	int D,P,last;
	for(int diff=0;diff<=20*m;++diff){
		if(dp[0][n][diff+OFFSET]!=-1){
			if(dp[0][n][diff+OFFSET] > dp[0][n][-diff+OFFSET]){
				P = (diff + dp[0][n][diff+OFFSET])/2;
				D = P - diff;
				last = prev[m][n][diff+OFFSET];
			}
			else{
				P = (-diff + dp[0][n][-diff+OFFSET])/2;
				D = P + diff;
				last = prev[m][n][-diff+OFFSET];
			}
			break;
		}
		else if(dp[0][n][-diff+OFFSET]!=-1){
			P = (-diff + dp[0][n][-diff+OFFSET])/2;
			D = P + diff;
			last = prev[m][n][-diff+OFFSET];
			break;
		}
	}
	int res[21];
	res[m] = last;
	int diff = P-D;
	for(int i=m-1;i>0;--i){
		last = res[i+1];
		diff += d[last]-p[last];
		res[i] = prev[i][last-1][diff+OFFSET];
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n",P,D);
	for(int i=1;i<=m;++i){
		printf(" %d",res[i]);
	}
	printf("\n\n");
}

int main(){
//	freopen("in.txt","r",stdin);
	int cas = 0;
	while(scanf("%d%d",&n,&m)!=EOF&&n>0){
		++cas;
		initialize();
		getDP();
		printf("Jury #%d\n",cas);
		print();
	}
	return 0;
}
