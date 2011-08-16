#include<cstdio>
#include<cstring>
using namespace std;
#define MAX (1<<30)
#define MAXN 100
int n;
long long count[MAXN+1];
long long fac(int n){
	long long m = n*n;
	return (m-3)*(m-2)*(m-1)*m;
}
int main(){
//	freopen("in.txt","r",stdin);
	count[2] = 1;
	count[3] = 6;
	int n;
	int p;
	for(int i=4;i<=MAXN;++i){
		count[i]=count[i-1];
		for(int j=2;j<=i;++j){
			count[i] += (j-1)*(2*i-2*j+1);
		}
	}
	while(scanf("%d%d",&n,&p)!=EOF && n>0){
		double res = 1.0*fac(n)*p/(2400*count[n]);
		printf("%.2lf\n",res);
	}
	return 0;
}
