#include<cstdio>
#include<cmath>
double GetLength(double H,double h,double d,double y)
{
	return y*H/(d+y)-(H-h)*y/H+h*d/H;
}
double LengthDaoshu(double H,double h,double d,double y)
{
	return H*d/((d+y)*(d+y))-(H-h)/H;
}
double GetLengthMax(double H,double h,double d)
{
	double ymax=h*d/(H-h);
	double ypoint=H*sqrt(d/(H-h))-d;
	if(ypoint>=0&&ypoint<=ymax)
		return GetLength(H,h,d,ypoint);
	else if(LengthDaoshu(H,h,d,0)>0)
		return GetLength(H,h,d,ymax);
	else
		return GetLength(H,h,d,0);
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		double H,h,d;
		scanf("%lf%lf%lf",&H,&h,&d);
		double ans=GetLengthMax(H,h,d);
		printf("%.3lf\n",ans);
	}
	return 0;
}
