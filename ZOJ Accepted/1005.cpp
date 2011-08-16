#include<iostream>
#include<cstdio>
using namespace std;

class Jug
{
private:
	int Ca,Cb,N;
public:
	void set0();
	int input();
	void generate();
	void output();
};

void Jug::set0()
{
	Ca=0;
}

int Jug::input()
{
	if(Ca)	cout<<endl;
	if(scanf("%d%d%d",&Ca,&Cb,&N)!=EOF)	return 1;
	else return 0;
}

void Jug::generate()
{
	int ja=0,jb=0;
	int flag=1;
	while(jb!=N&&flag>=0){
/*		if(ja==0&&jb==0){
			if(flag){
				jb=Cb;
				cout<<"fill B"<<endl;
			}
			else {
				ja=Ca;
				cout<<"fill A"<<endl;
			}
		}
		else if(ja==0&&jb!=0){
			if(jb<Ca){
				ja=jb;jb=0;
				cout<<"pour B A"<<endl;
			}
			else if(jb>Ca){
				jb=jb-Ca;
				cout<<"pour B A"<<endl<<"empty A"<<endl;
			}
			else {
				if(jb+Ca>Cb){
					jb=jb+Ca-Cb;
					cout<<"fill A"<<endl<<"pour B A"<<endl<<"empty B"<<endl;
				}
				else if(jb+Ca<Cb){
					jb=jb+Ca;
					cout<<"fill A"<<endl<<"pour A B"<<endl;
				}
				else {
					ja=Ca;
					cout<<"fill A"<<endl;
				}
			}
		}
		else if(ja!=0&&jb==0){
			if(ja==N){
				jb=ja;ja=0;
				cout<<"pour A B"<<endl;
			}
			else if(ja==Ca){
				ja=0;
				cout<<"empty A"<<endl;
				flag--;
			}
			else{
				jb=Cb;
				cout<<"fill B"<<endl;
			}
		}
		else if(ja!=0&&jb!=0){
			if(ja==N){
				jb=ja;ja=0;
				cout<<"empty B"<<endl<<"pour A B"<<endl;
			}
			else if(jb+ja==N){
				jb=jb+ja;
				cout<<"pour A B"<<endl;
			}
			else if(jb+Ca==N){
				jb=jb+Ca;
				cout<<"fill A"<<endl<<"pour A B"<<endl;
			}
			if(ja+jb<=Ca){
				ja=ja+jb;jb=0;
				cout<<"pour B A"<<endl;
			}
			else if(ja+jb>Ca&&ja+jb<=Cb){
				jb=ja+jb-Ca;ja=0;
				cout<<"pour B A"<<endl<<"empty A"<<endl;
			}
			else{
				jb=ja+jb-Ca;ja=0;
				cout<<"pour B A"<<endl<<"empty B"<<endl;
			}
		}*/
		ja=Ca;
		cout<<"fill A"<<endl;
		jb=jb+ja;ja=0;
		cout<<"pour A B"<<endl;
		if(jb>Cb) {
				jb-=Cb;
				cout<<"empty B"<<endl<<"pour A B"<<endl;
		}
	}
	cout<<"success";
}

int main()
{
	class Jug j;
	j.set0();
	while(j.input()){
		j.generate();
	}
	return 0;
}
