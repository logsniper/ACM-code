#include<iostream>
using namespace std;

class table{
private:
	int x,y;
	int n;
public:
	void input();
	void calculate();
	void output();
};

void table::input()
{
	cin>>x>>y;
}

void table::calculate()
{
	int tmp=0;
	while(x>3||y>2){
		x=x-2;
		y=y-2;
		tmp=tmp+4;
	}
	if(x==0&&y==0)	n=tmp;
	else if(x==2&&y==0)	n=tmp+2;
	else if(x==2&&y==2)	n=tmp+4;
	else if(x==1&&y==1)	n=tmp+1;
	else if(x==3&&y==1)	n=tmp+3;
	else n=-1;
}

void table::output()
{
	if(n==-1)
		cout<<"No Number"<<endl;
	else cout<<n<<endl;
}

int main()
{
	int N;
	cin>>N;
	class table T;
	while(N--){
		T.input();
		T.calculate();
		T.output();
	}
	return 0;
}
