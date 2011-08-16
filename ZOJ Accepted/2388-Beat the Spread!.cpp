#include<iostream>
using namespace std;

int main()
{
	int n;
	int sum,difference;
	int large,small;
	cin>>n;
	while(n--){
		cin>>sum>>difference;
		if(sum<difference||(sum+difference)%2) cout<<"impossible"<<endl;
		else {
			large=(sum+difference)/2;
			small=sum-large;
			cout<<large<<" "<<small<<endl;
		}
	}
	return 0;
}
