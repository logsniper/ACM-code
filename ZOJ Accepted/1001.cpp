#include<iostream>
using namespace std;

class PPlus
{
public:
	int a,b;
	int plus();
};

int PPlus::plus()
{
	return a+b;
}

int main()
{
	class PPlus tt;
	
	while(cin>>tt.a>>tt.b)
		cout<<tt.plus()<<endl;
	
	return 0;
}
