#include<iostream>
using namespace std;

class Num
{
private :
	long long n;
	int f[16];
public :
	long long input();
	void test();

};

long long Num::input()
{
	cin>>n;
	return n;
}

void Num::test()
{
	int p[16];
	int j;
	int shit=0;
	for(int i=0;i<16;i++) f[i]=0;
	for(int i=2;i<=16;i++){
		long long k=n;
		for(j=0;k!=0;j++){
			p[j]=k%i;
			k=(k-p[j])/i;
		}
		for(int t=0;t<j;t++){
			if(p[t]!=p[j-t-1]) break;
			if(t==j-1) f[shit++]=i;
		}
	}
	if(f[0]==0) cout<<"Number "<<n<<" is not a palindrom"<<endl;
	else {
		cout <<"Number "<<n<<" is palindrom in basis";
		for(int i=0;f[i]!=0;i++)	cout<<" "<<f[i];
		cout<<endl;	
	}
}

int main()
{
	class Num num;
	while(num.input())
		num.test();
}
