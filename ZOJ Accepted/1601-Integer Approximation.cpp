#include<cstdio>
#define abs(X) (X>0?X:-X)

int main()
{
	double a,min;
	int n,d,l;
	while(scanf("%lf%d",&a,&l)!=EOF){
//		printf("%.3lf\n",a);
		int tn,td;
		double tmin;
		min=100000;
		for(td=1;td<=l;++td){
			tn=int(td*a-1);
			if(tn>l)	continue;
			tmin=a-1.0*tn/td;
			if(abs(tmin)<min){
				min=abs(tmin);
				n=tn,d=td;
			}
			++tn;
			if(tn>l)	continue;
			tmin=a-1.0*tn/td;
			if(abs(tmin)<min){
				min=abs(tmin);
				n=tn,d=td;
			}
			++tn;
			if(tn>l)	continue;
			tmin=a-1.0*tn/td;
			if(abs(tmin)<min){
				min=abs(tmin);
				n=tn,d=td;
			}
		}
		printf("%d %d\n",n,d);
	}
	return 0;
}
