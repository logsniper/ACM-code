#include<iostream>
#include<math.h>
using namespace std;

int X[16],Y[16],Z[16];

class Point
{
private :
	int x,y,z;
	int mx,my,mz;
public:
	int input();
	void map();
	void output();
}; 

int Point::input()
{
	cin>>x>>y>>z;
	if(x==-1&&y==-1&&z==-1) return 0;
	else return 1;
}

void Point::map()
{
	float D,D_min;
	D_min=255*sqrt(3);
	for(int i=0;i<16;i++){
		D=sqrt((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i])+(z-Z[i])*(z-Z[i]));
		if(D<D_min) {
			D_min=D;
			mx=X[i];
			my=Y[i];
			mz=Z[i];
		}
	}
}

void Point::output()
{
	cout<<"("<<x<<","<<y<<","<<z<<") maps to ("<<mx<<","<<my<<","<<mz<<")"<<endl;
}

int main()
{
	class Point point;
	for(int i=0;i<16;i++)
		cin>>X[i]>>Y[i]>>Z[i];
	while(point.input()){
		point.map();
		point.output();
	}
}
