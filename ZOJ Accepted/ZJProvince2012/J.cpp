#include <cstdio>
#include <vector>
using namespace std;
#define LL long long

int AxByC(LL a,LL b,LL c,LL* x,LL* y){ // ax + by = c
	vector<LL> P;
	LL aa = a, bb = b;
	while(aa*bb != 0){
		LL q = aa%bb;
		LL p = (aa-q)/bb;
		P.push_back(p);
		aa = bb;
		bb = q;
	}
	LL abgcd = aa;
	if(c%abgcd >0)	return -1;
	int N = P.size();
	*x = 1;
	*y = 0;
	for(int i=N-1;i>=0;--i){
		LL xx = *y;
		LL yy = *x - *y*P[i];
		*x = xx;
		*y = yy;
	}
	*x *= c/abgcd;
	*y *= c/abgcd;
	return 0;
}

const LL INF = (1LL<<60);

int main(){
	int a,m;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&m);
		LL x,y;
		int ret = AxByC(a,m,1,&x,&y);
		while(x<=0) x+=m;
		if (ret != 0){
			printf("Not Exist\n");
		}
		else {
			printf("%lld\n",x);
		}
	}
	return 0;
}
