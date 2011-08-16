#include <cstdio>
#include <cmath>
#define PI 3.14159265359

double divide(double r,double x,bool small){//r圆的半径，x割线的圆心距，small是否取较小的部分
	if(x<0)	x=-x;
	double theta = 2*acos(x/r);
	double s = r*r*sin(theta)/2;
	double ret = r*r*theta/2 - s;
	if(small)	return ret;
	else			return PI*r*r-ret;
}

double area(double d,double r, double R)
{
	if(d>=r+R)	return 0;//相离
	double rs=r+R;
	r=r<R?r:R;
	R=rs-r;
	if(d+r<=R)		return PI*r*r;//内含
	double r2=r*r,R2=R*R,d2=d*d;
	double x2=(4*r2*R2-(d2-r2-R2)*(d2-r2-R2))/(4*d2);
	double d1=sqrt(r2-x2);
	if(r2+d2>R2){
		double d2=d-d1;
		return divide(r,d1,true)+divide(R,d2,true);
	}
	else{
		double d2=d+d1;
		return divide(r,d1,false)+divide(R,d2,true);
	}
}

int main()
{
	double x1,y1,r1,d;
	double x,y,r,R;
	while(scanf("%lf%lf%lf",&x1,&y1,&r1)!=EOF){
		scanf("%lf%lf%lf%lf",&x,&y,&r,&R);
		double d=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		double diff = area(d,r1,R)-area(d,r1,r);
		if(diff<0.0005)	printf("0.000\n");
		else printf("%.3lf\n",diff);
	}
	return 0;
}