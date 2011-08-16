#include<iostream>
#include<cstdio>
using namespace std;
long long NT(int n)
{
	long long num=0,k=2;
	for(k=2;k<=n;k*=2){
		num+=(long long)(n/k);
	}
	return num;
}

int main()
{
	int n,i;
	long long a,b,c;
	while((scanf("%d%d",&n,&i))!=EOF){
		if(n<i)	continue;
		a=NT(n);
		b=NT(i);
		c=NT(n-i);
		if(a>b+c)	cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}
	return 0;
}
