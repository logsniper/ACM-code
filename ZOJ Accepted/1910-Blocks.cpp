#include<iostream>
#include<cmath>
using namespace std;
int cubic(int N)
{
	int a,b,c,flag1,flag2;
	flag1=pow(N,double(1)/3)+1;
	for(a=flag1;a>0;a--){
		if(N%a!=0)	continue;
		flag2=double(N)/a;
		for(b=sqrt(double(flag2))+1;b>=a;b--){
			if(flag2%b==0){
				c=flag2/b;
//				cout<<a<<" "<<b<<" "<<c<<endl;
				return (a*b+b*c+c*a)*2;
			}
		}
	}
}

int main()
{
	int C,N;
	cin>>C;
	while(C--){
		cin>>N;
		int ans=cubic(N);
		cout<<ans<<endl;
	}
	return 0;
}
