#include<iostream>
#include<cstdio>
using namespace std;

int K=0;

class Undercut
{
private :
	int A[20],B[20];
	int N;
	int a,b;
public:
	int input();
	void generate();
	void output();
};

int Undercut::input()
{
	cin>>N;
	if(N==0) return 0;
	for(int i=0;i<N;i++)
			cin >>A[i];
	for(int i=0;i<N;i++)
			cin >>B[i];
	return 1;
}

void Undercut::generate()
{
	a=0;b=0;
	for(int i=0;i<N;i++){
		switch(A[i]-B[i]){
			case 0:
				break;
			case 1:
				if(B[i]!=1) {b+=A[i]+B[i];break;}
				else {b+=6;break;}
			case -1:
				if(A[i]!=1) {a+=A[i]+B[i];break;}
				else {a+=6;break;}
			default:
				if(A[i]-B[i]>0) {a+=A[i];break;}
				else {b+=B[i];break;}
		}
	}
}

void Undercut::output()
{
//	freopen("1057out.txt","w",stdout);
	cout<<"A has "<<a<<" points. B has "<<b<<" points."<<endl;
}

int main()
{
	class Undercut card;
	while (card.input()){
		card.generate();
		if(K++) cout<<endl;
		card.output();
	}
	return 0;
}
