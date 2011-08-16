#include<iostream>
using namespace std;

class hole{
private:
	int n,u,d;
public:
	int input();
	void output();
};

int hole::input()
{
	cin>>n>>u>>d;
	return n;
}

void hole::output()
{
	int k=1;
	int s=u;
	while(s<n){
		s-=d;
		s+=u;
		k+=2;
	}
	cout<<k<<endl;
}

int main()
{
	class hole H;
	while(H.input())
		H.output();
	return 0;
}
