#include<iostream>
using namespace std;
#define NUMBER 100
#define min(A,B) (A<B?A:B)
#define max(A,B) (A>B?A:B)

float Tmin,Tmax;

int main()
{
	int ant;
	int length;
	int N,n,i;
	cin>>N;
	while(N--){
		cin>>length>>n;
		Tmin=0;Tmax=0;
		for(i=0;i<n;i++){
			cin>>ant;
			if(min(ant,length-ant)>Tmin)	Tmin=min(ant,length-ant);
			if(max(ant,length-ant)>Tmax)	Tmax=max(ant,length-ant);
		}
		cout<<Tmin<<" "<<Tmax<<endl;
	}
	return 0;
}
