#include<iostream>
#include<cmath>
using namespace std;
int IsPrime(int n)
{
	int i;
	double s=sqrt(n);
	for(i=2;i<=s&&i<n;i++)
		if(n%i==0)	return 0;
	return 1;
}
int main()
{
	int PrimeNumber;
	int n,c;
	int i,k;
	int prime[200];
	prime[0]=1;
	for(k=2,PrimeNumber=1;k<1000;k++){
		if(IsPrime(k))	prime[PrimeNumber++]=k;
	}
//	cout<<PrimeNumber;
	while(cin>>n>>c){
		for(k=0;prime[k]<=n;k++);
		cout<<n<<" "<<c<<":";
//		cout<<k;
		if(k%2==0){
			if(c>k/2) c=k/2;
			for(i=k/2-c;i<k/2+c;i++)
				cout<<" "<<prime[i];
		}
		else{
			if(c>(k+1)/2) c=(k+1)/2;
			for(i=(k+1)/2-c;i<=(k-3)/2+c;i++)
				cout<<" "<<prime[i];
		}
		cout<<"\n\n";
	}
	return 0;
}
