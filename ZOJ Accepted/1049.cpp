#include<iostream>
using namespace std;

#define PI 3.1415926536
#define S 50;

class Land
{
private:
	float x,y;
	int Z;
public:
	void input();
	int erode();
};

void Land::input()
{
	cin>>x>>y;
}

int Land::erode()
{	
	float s;
	s=PI*(x*x+y*y)/2;
	Z=s/S+1;
	return Z+1;
}

int main()
{
	int N;
	class Land shit[100];
	cin>>N;
	for(int i=0;i<N;i++)
		shit[i].input();
	for(int i=0;i<N;i++)
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<shit[i].erode()<<"."<<endl;
	cout<<"END OF OUTPUT."<<endl;
}
