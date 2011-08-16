#include<iostream>
#include<cstdio>
using namespace std;
typedef class number
{
private:
	long x;
	long y;
public:
	void input();
	void calculate();
	void output();
}NUM;

void number::input()
{
	cin>>x;
}

void number::calculate()
{
	long tmp=x;
	long s=10;
	while(tmp/s!=0){		
		if(tmp%s>=(5*s/10)){
			tmp=tmp/s;
			tmp++;
			tmp=tmp*s;
		}
		else{
			tmp=tmp/s;
			tmp=tmp*s;
		}
			s*=10;
	}
	y=tmp;
}

void number::output()
{
	cout<<y<<endl;
}

int main()
{
	int N;
	NUM obj;
	cin>>N;
	while(N--){
		obj.input();
		obj.calculate();
		obj.output();
	}
	return 0;
}
