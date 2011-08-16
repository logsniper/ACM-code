#include<cstdio>
#include<cmath>
#define PI 3.14159265359
using namespace std;
int main()
{
	double k,h,a,b,dist,angle;
	while(scanf("%lf%lf%lf%lf",&k,&h,&a,&b)!=EOF){
		angle=k/180*PI;
		double l=(h-a)*cos(angle)*2;
		double x=l*sin(angle);
		double y=a+l*cos(angle);
		dist=sqrt((x-b)*(x-b)+y*y);
		printf("%.2lf\n",dist);
	}
	return 0;
}
