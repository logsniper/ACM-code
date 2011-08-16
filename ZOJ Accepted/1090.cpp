#include <iostream>
#include<cstdio>
#include<math.h>
using namespace std;
#define PI 3.141592653589793

int main()
{
	double x1,y1,x2,y2,x3,y3;
	double a,b,c;
	double D,C;
	while((scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3))!=EOF){
		a=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
 		b=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
 		c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
 		
 		double sinA,cosA;
		cosA=(b*b+c*c-a*a)/(2*b*c);
		sinA=sqrt(1-cosA*cosA);
		D=a/sinA;
		if(D>1000000) break;
		C=D*PI;
		printf("%.2f\n",C);
	}
	return 0;
}
