#include<iostream>
#define C(N) (N*N*N)
#define shit3 1.44224957
using namespace std;

int main()
{
	bool flag[200];
	long a,b,c,d;
	for(a=6;a<=200;a++)
		for(b=2;b<a;b++){
			for(c=b;c<a;c++)
				for(d=c;d<a;d++)
					if(C(a)==C(b)+C(c)+C(d))
						cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
		}
}
