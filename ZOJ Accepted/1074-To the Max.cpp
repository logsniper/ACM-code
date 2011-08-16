#include<iostream>
using namespace std;
int Matrix[101][101];
int MaxSum(int n,int *a)
{
	int sum=0,b=0;
	for(int i=1;i<=n;i++){
		if(b>0)	b+=a[i];
		else b=a[i];
		if(b>sum)	sum=b;
	}
	return sum;
}
int MaxSum2(int n)
{
	int sum=0,i,j,k;
	int *b=new int [n+1];
	for(i=1;i<=n;i++){
		for(k=1;k<=n;k++)	b[k]=0;
		for(j=i;j<=n;j++){
			for(k=1;k<=n;k++)	b[k]+=Matrix[j][k];
			int max=MaxSum(n,b);
			if(max>sum)	sum=max;
		}
	}
	return sum;
}
int main()
{
	int n,i,j;
	while(cin>>n){
		for(j=1;j<=n;j++)
			for(i=1;i<=n;i++)
				cin>>Matrix[j][i];
		int ans=MaxSum2(n);
		cout<<ans<<endl;
	}
	return 0;
}
