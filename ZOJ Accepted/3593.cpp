#include <cstdio>
#include <vector>
using namespace std;
#define LL long long

LL gcd(LL x,LL y){
	if(x == 0)	return y;
	else	return gcd(y%x,x);
}

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
	LL A,B,a,b;
	int T;
	scanf("%d",&T);
	while(T--){
		LL res = -1;
		scanf("%lld%lld%lld%lld",&A,&B,&a,&b);
		LL dist = A>B?A-B:B-A;
		LL abgcd = gcd(a,b);
		if (dist%abgcd != 0){
			res = -1;
		} else {
			LL x0,y0;
			AxByC(a,b,dist,&x0,&y0);
			LL min = INF;
			LL x,y,step;
			LL C;
			LL X,Y;
			C = abgcd*(y0-x0)/(a+b);
			for (int i=-2;i<=2;++i){
				x = x0 + b*(C+i)/abgcd;
				y = y0 - a*(C+i)/abgcd;
				step = x>y?x:y;
				if(x*y >= 0){
					if(min > step){
						min = step;
						X = x;
						Y = y;
					}
				}
			}
			C = -x0*abgcd/b;
			for (int i=-2;i<=2;++i){
				x = x0 + b*(C+i)/abgcd;
				y = y0 - a*(C+i)/abgcd;
				if(x*y<=0){
					step = x>y?x-y:y-x;
					if(min > step){
						min = step;
						X = x;
						Y = y;
					}
				}
			}
			C = y0*abgcd/a;
			for (int i=-2;i<=2;++i){
				x = x0 + b*(C+i)/abgcd;
				y = y0 - a*(C+i)/abgcd;
				if(x*y<=0){
					step = x>y?x-y:y-x;
					if(min > step){
						min = step;
						X = x;
						Y = y;
					}
				}
			}
			res = min;
			// printf("%lld*%lld+%lld*%lld=%lld\n",a,X,b,Y,dist);
		}
		printf("%lld\n",res);
	}
	return 0;
}
