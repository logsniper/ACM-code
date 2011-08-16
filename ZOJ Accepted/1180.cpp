#include<iostream>
#include<cstdio>
using namespace std;

class Num
{
private:
	long T;
	int k[7];
	bool flag;
public:
	void init();
	void exp();
	int check();
	void print();
};

void Num::init()
{
	T=65;
	flag=0;
	for(int i=0;i<7;i++)	k[i]=0;
}


void Num::exp()
{
	flag=1;
	for(long t=T-54;t<T;t++){
		long s=t,p=t;
		for(int i=0;p;i++){
			k[i]=p%10;
			s+=k[i];
			p=(int)p/10;
		}
		if(s==T) flag=0; 
	}
}

int Num::check()
{
	T++;
	if(T<=1000000) return 1;
	else return 0;
}

void Num::print()
{
	if(flag) printf("%d\n",T);
}

int main()
{
	class Num num;
//	freopen("1180out.txt","w",stdout);
	num.init();
	printf("1\n");
	printf("3\n");
	printf("5\n");
	printf("7\n");
	printf("9\n");
	printf("20\n");
	printf("31\n");
	printf("42\n");
	printf("53\n");
	printf("64\n");
	while(num.check()){
		num.exp();
		num.print();
	}
	return 0;
}
