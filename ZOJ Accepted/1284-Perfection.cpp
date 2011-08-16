#include<iostream>
using namespace std;

class Perf
{
private:
	int t;
	int s;
public:
	bool input();
	int judge();
	void f();
	void output();
};

bool Perf::input()
{
	cin>>t;
	if(t==0) return 0;
	return 1;
}

int Perf::judge()
{
	int sum=0,i;
	float tmp1=0;
	int tmp2=0;
	for(i=1;i<=t/2;i++){
		tmp1=(float)t/i;
		tmp2=(int)(t/i);
		if(tmp1==tmp2)	sum+=i;
	}
	if(sum<t) return 1;
	else if(sum>t) return 3;
	else return 2;
}

void Perf::f()
{
	if(t<10) cout<<"    ";
	else if(t<100) cout<<"   ";
	else if(t<1000) cout<<"  ";
	else if(t<10000) cout<<" ";
}

void Perf::output()
{
	switch(Perf::judge()){
		case 1:Perf::f();cout<<t<<"  DEFICIENT"<<endl;break;
		case 2:Perf::f();cout<<t<<"  PERFECT"<<endl;break;
		case 3:Perf::f();cout<<t<<"  ABUNDANT"<<endl;break;
	}
}

int main()
{
	class Perf P[100];
	int n=0;
	while(P[n++].input());
	n--;
	cout<<"PERFECTION OUTPUT"<<endl;
	for(int i=0;i<n;i++)
		P[i].output();
	cout<<"END OF OUTPUT";
}
