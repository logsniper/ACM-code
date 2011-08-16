#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	if(a%b==0)	return b;
	if(b%a==0)	return a;
	if(a>b)	return gcd(b,a%b);
	else	return gcd(b,b%a);
}

long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}

int main()
{
	int N;
	cin>>N;
	while(N--){
		int n;
		int now,ans=1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>now;
			ans=lcm(ans,now);
		}
		cout<<ans<<endl;
	}
}
