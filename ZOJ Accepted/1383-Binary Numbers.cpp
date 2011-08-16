#include<iostream>
using namespace std;

int main()
{
	int d;
	int A,a[20];
	cin>>d;
	while(d--){
		cin>>A;
		for(int i=0;A&&i<20;i++){
			a[i]=A%2;
			A>>=1;
			if(a[i]==1){
				cout<<i;
				if(A>0) cout<<" ";
			}
		}
		if(d) cout<<endl;
	}
}
