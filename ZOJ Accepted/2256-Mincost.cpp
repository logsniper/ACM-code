#include<cstdio>
using namespace std;
int main()
{
	float way_f;
	float cost;
	int way;
	while(scanf("%f",&way_f)&&way_f!=0){
		way=(int)way_f;
		if(way<way_f) way++;
		cost=0;
		while(way>13){
			way-=8;
			cost+=18;
		}
		if (way<=4) cost+=10;
		else if(way<=8)	cost+=(float)(10+2*(way-4));
		else cost+=(float)(18+2.4*(way-8));
		if(cost==(int)cost)
			printf("%.0f\n",cost);
		else
			printf("%.1f\n",cost);
	}
	return 0;
}
