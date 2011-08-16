#include<iostream>
#include <cstdio>
using namespace std;

double RATE[5][5];

class Currency
{
private:
	double rate[5][5];
public:
	void input();
};

void Currency::input()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			cin>>rate[i][j];
			RATE[i][j]=rate[i][j];
		}
}



class Trip
{
private :
	int n,place[12];
	double money0,money1;
public:
	int input();
	double OnTrip();
};

int Trip::input()
{
	cin>>n;
	if(n==0) return 0;
	place[0]=1;
	for(int i=1;i<=n;i++) cin>>place[i];
	place[n+1]=1;
	cin>>money0;
	return 1;
}

double Trip::OnTrip()
{
	double tmp=money0*1000;
	
	for(int i=0;i<=n;i++){
		tmp=tmp*RATE[place[i]-1][place[i+1]-1];
		tmp=(int)(tmp/10+0.5);
		tmp*=10;
	}
	
//	tmp=(int)(tmp/10+0.5);	
	money1=(double)(tmp/1000);
	
	return money1;
}

int main()
{
	class Currency ccy;
	class Trip tp;
	int N;
	cin>>N;
	while(N--){
		
		ccy.input();
	
		while(tp.input())
			printf("%.2lf\n",tp.OnTrip());
		if(N) printf("\n");
	}
	return 0;
}
