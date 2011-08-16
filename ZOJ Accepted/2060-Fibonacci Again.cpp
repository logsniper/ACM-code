#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n%4==2) cout<<"yes"<<endl;
		else cout<<"no"<<endl; 
	}
	return 0;
}
