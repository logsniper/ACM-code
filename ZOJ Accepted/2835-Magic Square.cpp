#include<iostream>
using namespace std;
int a[10][10];
int IsMagic(int n){
	int i,j;
	int k,N,max,min;
	int b[1001];
	int sum1=0,sum2,avg;
	
	N=n*n;
	max=0;min=1000;
	for(k=0;k<=1000;k++)	b[k]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			k=a[i][j];
			b[k]++;
			if(max<k)	max=k;
			if(min>k)	min=k;
			}
	for(k=min;k<=max;k++)
		if(b[k]>1)	return 0;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum1+=a[i][j];
	avg=sum1/(n);
	sum1=0;sum2=0;
	for(i=0;i<n;i++){
		sum1+=a[i][i];
		sum2+=a[i][n-1-i];
	}
	if(sum1!=avg||sum2!=avg)	return 0;
	for(i=0;i<n;i++){
		sum1=0;sum2=0;
		for(j=0;j<n;j++){
			sum1+=a[i][j];
			sum2+=a[j][i];
		}
		if(sum1!=avg||sum2!=avg)	return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	int n;
	while(cin>>n&&n!=0){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>a[i][j];
		if(IsMagic(n))	cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
