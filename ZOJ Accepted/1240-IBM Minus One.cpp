#include<iostream>
#include<cstdio>
using namespace std;

class Alph
{
private:
	char a[51];
	int k;
public:
	void input();
	void translate();
	void output();
};

void Alph::input()
{
	k=0;
	do{
		scanf("%c",&a[k]);
//		cin>>a[k];
	}while(a[k++]!='\n');
	k--;
}

void Alph::translate()
{
	for(int i=0;i<k;i++){
		if(a[i]=='Z') a[i]='A';
		else a[i]=a[i]+1;
	}
}

void Alph::output()
{
	for(int i=0;i<k;i++)
		printf("%c",a[i]);
}

int main()
{
	int p;
//	cin>>p;
	scanf("%d%*c",&p);
	int I=1;
	class Alph alph;
	while(p--){
		alph.input();
		alph.translate();
		printf("String #%d\n",I++);
		alph.output();
		printf("\n\n");
	}
	return 0;
}
