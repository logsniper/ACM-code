#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#define MAX (1LL<<60)
#define MAXN 500000
#define ABS(X) ((X)<0?(-(X)):(X))
using namespace std;

int factorCount[MAXN+1];
int sum[MAXN+1];

void initialize(){
	memset(factorCount,0,sizeof factorCount);
	sum[0] = 0;
	for(int i=2;i<=MAXN;++i){
		int m = (int)sqrt(i);
		for(int j=2;j<=m;++j){
			if(i%j==0){
				factorCount[i] = factorCount[i/j]+1;
				break;
			}
		}
		if(factorCount[i] == 0)	factorCount[i]=1;
		sum[i] = sum[i-1]+factorCount[i];
	}
}

int main(){
	long long x,y,z;
	long s = clock();
	initialize();
//	freopen("in.txt","r",stdin);
	while(scanf("%lld%lld%lld",&x,&y,&z)!=EOF){
		long long res = 0;
		res = y*z*sum[x]+x*z*sum[y]+x*y*sum[z]+x*y*z;
		printf("%lld\n",res);
	}
	long e = clock();
//	printf("initialize time = %.3f s\n",1.0f*(e-s)/CLOCKS_PER_SEC);
	return 0;
}
