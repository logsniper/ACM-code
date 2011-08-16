#include<iostream>
using namespace std;

int main()
{
	int n,k;
	int ans,ans_10;
	while(cin>>n){
		if(n%2==0||n%5==0)	continue;
		ans=1%n;
		for(k=1;ans!=0;k++)
			ans=(ans*10+1)%n;
		cout<<k<<endl;
	}
	return 0;
}
