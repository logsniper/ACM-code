#include<iostream>
using namespace std;

void prison(bool a[],int n,int i)
{
	for(int j=1;i*j<=n;j++)
		a[i*j-1]=!a[i*j-1];
}

int main()
{
	int N;
	bool a[101];
	int n,i;
	int num;
	cin>>N;
	while(N--){
		cin>>n;
		num=0;
		for(i=0;i<n;i++) a[i]=0;
		for(i=1;i<=n;i++)
			prison(a,n,i);
		for(i=0;i<n;i++)
			if(a[i]==1) num++;
		cout<<num<<endl;
	}
	return 0;
}
