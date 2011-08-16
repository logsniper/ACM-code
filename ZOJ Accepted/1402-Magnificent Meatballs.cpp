#include<iostream>
using namespace std;
int main()
{
	int a[31];
	int i,s,half;
	while(cin>>a[0]&&a[0]!=0){
		s=0;
		for(i=1;i<=a[0];i++){
			cin>>a[i];
			s+=a[i];
		}
		if(s%2){
			cout<<"No equal partitioning.\n";
			continue;
		}
		half=0;
		for(i=1;half<s/2;i++)
			half+=a[i];
		i--;
		if(half!=s/2)
			cout<<"No equal partitioning.\n";
		else
			cout<<"Sam stops at position "<<i<<" and Ella stops at position "<<i+1<<".\n";
	}
	return 0;
}
