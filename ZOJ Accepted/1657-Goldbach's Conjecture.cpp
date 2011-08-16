#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int n)
{
	if(n==1)	return 0;
	int k=int(sqrt(n));
	for(int i=2;i<=k;i++)
		if (n%i==0)	return 0;
	return 1;
}

int main()
{
	int n,k;
	int ans;
	while(cin>>n&&n!=0){
		ans=0;
		for(k=2;k<=(n+1)/2;k++)
			if(IsPrime(k)&&IsPrime(n-k)){
				ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
