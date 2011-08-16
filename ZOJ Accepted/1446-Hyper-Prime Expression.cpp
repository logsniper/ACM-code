#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN (20000)

int dp[20001];
string res[20001];

class Power{
public:
	int a;
	int b;
	int p;//p = a^b
	bool operator<(const Power &b)const{
		return p<b.p;
	}
};
vector<Power> pw;

void getResult(){
	int m = (int)sqrt(MAXN);
	for(int k=2;k<=m;++k){
		int t = k*k;
		for(int i=2;t<=MAXN;++i,t*=k){
			Power np;
			np.a = k;
			np.b = i;
			np.p = t;
			pw.push_back(np);
		}
	}
	sort(pw.begin(),pw.end());
/*	for(int i=0;i<pw.size();++i){
		printf("%d %d %d\n",pw[i].a,pw[i].b,pw[i].p);
	}*/
	memset(dp,0,sizeof dp);
	dp[1] = dp[2] = dp[3] = dp[5] = dp[6] = dp[7] = 1;
	dp[4] = 2;
	res[1] = "1";
	res[2] = "2";
	res[3] = "3";
	res[4] = "(2+2)";
	res[5] = "5";
	res[6] = "3!";
	res[7] = "7";
	int fac = 6;
	for(int i=3;fac<=MAXN;){
		dp[fac] = dp[i];
		res[fac] = res[i]+"!";
		fac *= (++i);
	}
	int pwi=0;
	for(int k=4;k<=MAXN;++k){
		for(int i=1;i<=k/2;++i){
			if(dp[k]==0 || dp[k]>dp[i]+dp[k-i]){
				dp[k] = dp[i]+dp[k-i];
				res[k] = "("+res[i]+"+"+res[k-i]+")";
			}
		}
		m = (int)sqrt(k);
		for(int i=2;i<=m;++i){
			if(k%i==0){
				int j = k/i;
				if(dp[k]==0 || dp[k]>dp[i]+dp[j]){
					dp[k] = dp[i]+dp[j];
					res[k] = "("+res[i]+"*"+res[j]+")";
				}
			}
		}
		while(pwi<pw.size() && pw[pwi].p < k){	++pwi;	}
		while(pwi<pw.size() && pw[pwi].p == k){
			if(dp[k]==0 || dp[k]>dp[pw[pwi].a]+dp[pw[pwi].b]){
				dp[k] = dp[pw[pwi].a]+dp[pw[pwi].b];
				res[k] = "("+res[pw[pwi].a]+"^"+res[pw[pwi].b]+")";
			}
			++pwi;
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	long s = clock();
	getResult();
	long e = clock();
//	printf("%f\n",1.0f*(e-s)/CLOCKS_PER_SEC);
	int n;
	while(scanf("%d",&n)!=EOF){
//		printf("%d ",n);
		printf("%s\n",res[n].c_str());
	}
	return 0;
}
