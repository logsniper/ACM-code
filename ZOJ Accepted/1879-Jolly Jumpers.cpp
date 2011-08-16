#include<iostream>
using namespace std;
int main()
{
	int n,num[3001];
	bool appear[3001];
	int i;
	while(cin>>n){
		bool flag=1;
		for(i=0;i<=n;i++)
			appear[i]=0;
		for(i=0;i<n;i++){
			cin>>num[i];
			if(i>0){
				int k=(num[i]-num[i-1]>0)?(num[i]-num[i-1]):(num[i-1]-num[i]);
//				cout<<k<<" ";
				if(k<n)
					appear[k]=1;
			}
		}
		for(i=1;i<n;i++)
			if(appear[i]==0){
				flag=0;
				break;
			}
		if(flag)	cout<<"Jolly\n";
		else cout<<"Not jolly\n";
	}
	return 0;
}
