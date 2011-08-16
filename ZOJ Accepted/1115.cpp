#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

class Number
{
private:
	char s[1000000];
	int t[1000000];
	long sum;
	long i;
public:
	int input();
	void output();
};

int Number::input()
{
	i=0;
	int j;
	do{
		scanf("%c",&s[i]);
		}
		while(s[i++]!='\n');		//以字母f标记number输入结束 
	i--;
	for(j=0;j<i;j++){
		t[j]=(int)s[j]-48;
	}
	if(i==1&&t[0]==0) return 0;
	else return 1;
}

void Number::output()
{
	sum=0;
	long n;
	for(int j=0;j<i;j++)
		sum+=t[j];
	while(sum>9){
		n=sum;
		sum=0;
		while(n!=0){
			sum+=n%10;
			n=(long)n/10;
		}
	}
	cout<<sum<<endl;
}

int main()
{
	Number num;
	while(num.input())
		num.output();
	return 0;
}
