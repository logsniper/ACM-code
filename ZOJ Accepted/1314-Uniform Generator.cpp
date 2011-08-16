#include<iostream>
using namespace std;
int main()
{
	int step,mod,min;
	int flag,i;
	int tmp,space1,space2;
	while(cin>>step>>mod){
		flag=1;
		min=step>mod?mod:step;
		for(i=2;i<=min;i++)
			if(step%i==0&&mod%i==0){
				flag=0;
				break;
			}
		for(tmp=step,space1=0;tmp>0;tmp/=10)	space1++;
		for(tmp=mod,space2=0;tmp>0;tmp/=10)	space2++;
		for(i=0;i<10-space1;i++)	cout<<" ";
		cout<<step;
		for(i=0;i<10-space2;i++)	cout<<" ";
		cout<<mod;
		if(flag)
			cout<<"    Good Choice\n";
		else
			cout<<"    Bad Choice\n";
		cout<<endl;
	}
	return 0;
}
