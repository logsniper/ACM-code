#include<cstdio>
#include<cmath>
const double e = 2.718281828;
double binarysearch(double tgt,double from,double to)
{
	if(from + 0.000001 > to)
		return from;
	double mid = (from+to)/2;
	double midvalue = mid/log(mid);
	if(midvalue<tgt)
		return binarysearch(tgt,mid+0.000001,to);
	else
		return binarysearch(tgt,from,mid-0.000001);
}
int main()
{
	double a,b;
	while(scanf("%lf",&a)!=EOF){
		if(a>e)	printf("-1\n");
		else if(a==e)
			printf("2.71828\n");
		else{
			double tgt = a/log(a);
			double b=binarysearch(tgt,e,50);
			printf("%.5lf\n",b);
		}
	}
	return 0;
}
