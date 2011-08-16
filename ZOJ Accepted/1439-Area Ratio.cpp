#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int x1,y1,z1;
	int x2,y2,z2;
	int x3,y3,z3;
	double ratio;
	while(cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3){
		double a,b,c;
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)+(z1-z3)*(z1-z3));
		c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2));
		
		double p,s,r;
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		r=s/p;
		
		double cosA,sinA,R;
		cosA=(b*b+c*c-a*a)/(2*b*c);
		sinA=sqrt(1-cosA*cosA);
		R=a/(sinA*2);
		
		ratio=r*r/(R*R);
		printf("%.3lf\n",ratio);
	}
	return 0;
}
