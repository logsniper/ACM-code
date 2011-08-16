#include<iostream>
using namespace std;
int main()
{
	int n;
	int a,b,c;
	while(cin>>n){
		int tmp=n;
		a=tmp%10;
		tmp/=10;
		b=tmp%10;
		tmp/=10;
		c=tmp;
		if(n==(a*a*a+b*b*b+c*c*c))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
