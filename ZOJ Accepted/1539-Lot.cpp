#include<iostream>
using namespace std;
int lot(int n)
{
	if(n<3)	return 0;
	if(n==3)	return 1;
	return lot(n/2)+lot((n+1)/2);
}
int main()
{
	int n;
	while(cin>>n){
		cout<<lot(n)<<endl;
	}
	return 0;
}
