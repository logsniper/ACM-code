#include<iostream>
using namespace std;

int NextSeq(bool io[],int n)
{
	int pi=0,po,j,k;

		pi=0;po=0;
		for(j=n-2;!(io[j+1]==0&&io[j]==1);j--){
			if(io[j+1])	pi++;
			else po++;
			if(pi==6)	return 0;
		}
		io[j]=0;
		for(k=1;k<=pi+1;k++)	io[j+k]=1;
		j=j+pi+2;
		for(k=0;k<=po;k++)	io[j+k]=0;
		
	return 1;
}

int main()
{
	int k,i;
	int a[13],num;
	bool io[13];
	cin>>k;
	while(1){
		if(k==0) break;
		for(i=0;i<k;i++)	cin>>a[i];
		for(i=0;i<6;i++)	io[i]=1;
		for(;i<k;i++)	io[i]=0;
		do{
			num=0;
			for(i=0;i<k;i++){
				if(io[i]){
					cout<<a[i];num++;
					if(num!=6)	cout<<' ';
				}
			}
			cout<<endl;
		}while(NextSeq(io,k));
		cin>>k;
		if(k!=0) cout<<endl;
	}
	return 0;
}
