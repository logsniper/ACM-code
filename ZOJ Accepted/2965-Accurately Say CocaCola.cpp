#include<iostream>
using namespace std;
int cc(int n){
	if(n%7==0)	return 1;
	while(n>=7){
		if(n%10==7)	return 1;
		n/=10;
	}
	return 0;
}

int main()
{
	int T,p;
	int k,i,num;
	cin>>T;
	while(T--){
		cin>>p;
		k=p;
		while(1){
			num=0;
			for(i=0;i<p;i++){
				if(cc(k+i))	num++;
			}
			if(num==p)	break;
			k++;
		}
		cout<<k<<endl;
	}
	return 0;
}
