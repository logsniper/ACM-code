#include<iostream>
using namespace std;

int main()
{
	int d;
	long n,o,p;
	cin>>d;
	while(d--){
		cin>>n;
		o=n;
		for(p=0;o%2==0;p++) o/=2;
		cout<<o<<" "<<p<<endl;		
	}
}
