#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.14159265359
int main()
{
	double D,V,d;
	double v1,v2;
	while(cin>>D>>V&&!(D==0&&V==0)){
		v1=D*D*D;
		v2=v1-double(V*12)/(2*PI);
		double k=double(1)/3;
		d=double(pow(v2,k));
		printf("%.3lf\n",d);
	}
	return 0;
}
