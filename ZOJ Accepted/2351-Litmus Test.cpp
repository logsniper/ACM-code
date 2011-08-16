#include<cstdio>
#include<cmath>
int main()
{
	int N;
	double k,c,ph;
	int m,n;
	scanf("%d",&N);
	while(N--){
		while(scanf("%lf%lf%d%d",&k,&c,&m,&n)){
			if(k==0&&c==0&&m==0&&n==0)	break;
			double h=(sqrt(k*k+4*m*n*k*c)-k)/(2*n*1.0f);
			ph = - log10(h);
			printf("%.3lf\n",ph);
		}
		if(N)	printf("\n");
	}
	return 0;
}
