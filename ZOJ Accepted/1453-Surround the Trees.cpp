#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x[100],y[100],n,i;
	int last_x,last_y,x_0,y_0;
	int next_x,next_y;
	int start,now;
	double total,current;
	double costmp,cosmax;
	double ax,ay,bx,by;
	bool flag[100];
	while(cin>>n&&n!=0){
		for(i=0;i<n;i++)
			cin>>x[i]>>y[i];

		total=0;
		x_0=x[0];y_0=y[0];start=0;
		flag[0]=0;
		for(i=1;i<n;i++){
			flag[i]=0;
			if(x[i]<x_0){
				x_0=x[i];
				y_0=y[i];
				start=i;
			}
			else if(x[i]==x_0&&y[i]<y_0){
				y_0=y[i];
				start=i;
			}
		}
		flag[start]=1;
		last_x=x_0;last_y=y_0-1;
		now=start;

		do{
			cosmax=-1;
			next_x=x_0;next_y=y_0;
			for(i=0;i<n;i++){
				if(flag[i]&&i!=start)	continue;
				ax=x_0-last_x;
				ay=y_0-last_y;
				bx=x[i]-x_0;
				by=y[i]-y_0;
				costmp=sqrt(double((ax*ax+ay*ay)*(bx*bx+by*by)));
				if(costmp==0)	continue;
				costmp=double(ax*bx+ay*by)/costmp;
				if(costmp>cosmax||(costmp==cosmax&&fabs(x[i]-x_0)>fabs(next_x-x_0))){
					cosmax=costmp;
					next_x=x[i];
					next_y=y[i];
					now=i;
				}
			}
			flag[now]=1;
			total+=sqrt((next_x-x_0)*(next_x-x_0)+(next_y-y_0)*(next_y-y_0));
			last_x=x_0;last_y=y_0;
			x_0=next_x;y_0=next_y;
		}while(now!=start);
		printf("%.2lf\n",total);
	}
	return 0;
}
