#include<iostream>
#include<cmath>
using namespace std;
int IsPrime(int n)
{
	int i,k;
	k=sqrt(double(n));
	for(i=2;i<=k;i++)
		if(n%i==0)	return 0;
	return 1;
}

int main()
{
	int n;
	while(cin>>n&&n!=0){
		int now=n,k,ans=n;
		for(k=2;!IsPrime(now);k++){
			if(now%k!=0||!IsPrime(k))	continue;
			while(now%k==0)	now/=k;
			ans=ans/k*(k-1);
//			cout<<k<<" ";
		}
		if(now!=1)
			ans=ans/now*(now-1);
		cout<<ans<<endl;
	}
	return 0;
}
