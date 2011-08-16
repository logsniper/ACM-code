#include<iostream>
#include<iomanip>
using namespace std;

class E
{
private:
	double e[10];
public:
	int fuck();
};

int E::fuck()
{
	int i;
	e[0]=1;
	double s=1;

	for(i=1;i<10;i++){
		s=(double)s/i;
		e[i]=e[i-1]+s;
	}
	for(i=0;i<3;i++)
		cout<<i<<" "<<e[i]<<endl;
	for(i=3;i<10;i++){
		cout.precision(9); 
		cout.setf(ios::fixed); 
		cout<<i<<" "<<e[i]<<endl;
	}
}

int main()
{
	E shit;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	shit.fuck();
}
