#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	float x1,y1,r1;
	float x2,y2,r2;
	float x,y;
	cin>>N;
	while(N--){
		cin>>x1>>y1>>r1;
		cin>>x2>>y2>>r2;
		if(r1>r2&&(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>(r1-r2)*(r1-r2)){
			y=(y2*r1-y1*r2)/(r1-r2);
			x=(x2*r1-x1*r2)/(r1-r2);
			printf("%.2f %.2f\n",x,y);
		}
		else if(r1<r2&&(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>(r1-r2)*(r1-r2)){
			y=(y2*r1-y1*r2)/(r1-r2);
			x=(x2*r1-x1*r2)/(r1-r2);
			printf("%.2f %.2f\n",x,y);
		}
		else printf("Impossible.\n");
	}
}
