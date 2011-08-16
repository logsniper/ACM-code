#include<iostream>
#include<cstdio>
using namespace std;

class Parentheses
{
private:
	int para[40];
	int Ps[20],Ws[20];
	int n;
public:
	void input();
	void translate1();
	void translate2();
	void output();
};

void Parentheses::input()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>Ps[i];
}

void Parentheses::translate1()
{
	int i,j;
	for(i=0;i<n*2;i++)	para[i]=0;
	for(i=0;i<n;i++){
		int p=Ps[i];
		para[p+i]=1;
	}
}

void Parentheses::translate2()
{
	int R[20];
	int i,j=0,s;
	int t,sum;
	for(i=0;i<n*2;i++)
		if(para[i]==1) R[j++]=i;
	for(i=0;i<n;i++){
		s=R[i];
		t=0;sum=0;
		for(j=s;;j--){
			if(para[j]==1) {t++;sum++;}
			else t--;
			if(t==0) break;
		}
		Ws[i]=sum;
	}
}

void Parentheses::output()
{
	cout<<Ws[0];
	for(int i=1;i<n;i++)
		cout<<" "<<Ws[i];
	cout<<endl;
}

int main()
{
	int t;
	class Parentheses nice[10];
	
//	freopen("1016.txt","r",stdin);
//	freopen("1016out.txt","w",stdout);
	
	cin>>t;
	for(int i=0;i<t;i++){
		nice[i].input();
		nice[i].translate1();
		nice[i].translate2();
	}
	for(int i=0;i<t;i++)
		nice[i].output();
	return 0;
}
