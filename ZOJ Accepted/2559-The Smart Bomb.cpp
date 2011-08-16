#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	long x[3],y[3];
	long long a,b;
	double l[3];
	double r[3];
	int i;
	while(scanf("%ld%ld%ld%ld%ld%ld",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])!=EOF){
		for(i=0;i<3;i++){
			a=(long long)(x[(i+1)%3]-x[(i+2)%3])*(x[(i+1)%3]-x[(i+2)%3]);
			b=(long long)(y[(i+1)%3]-y[(i+2)%3])*(y[(i+1)%3]-y[(i+2)%3]);
			l[i]=(double)sqrt(a+b);
		}
		for(i=0;i<3;i++){
			r[i]=(l[(i+1)%3]+l[(i+2)%3]-l[i])/2;
			printf("%.6f\n",r[i]);			
		}
	}
	return 0;
}
