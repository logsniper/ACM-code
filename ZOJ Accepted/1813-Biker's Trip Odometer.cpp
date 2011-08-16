#include<cstdio>
#define PI 3.1415927
using namespace std;
int main()
{
	double diameter,time;
	long revolutions;
	double distance,mph;
	int trip=1;
	while(scanf("%lf%ld%lf",&diameter,&revolutions,&time)!=EOF&&revolutions!=0){
		distance=diameter*PI*revolutions/(12*5280);
		mph=distance/time*3600;
		printf("Trip #%d: %.2f %.2f\n",trip++,distance,mph);
	}
	return 0;
}
