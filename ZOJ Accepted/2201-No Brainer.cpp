#include<iostream>
using namespace std;
int main()
{
	int n;
	int x,y;
	cin>>n;
	while(n--){
		cin>>x>>y;
		if(x<y) cout<<"NO BRAINS"<<endl;
		else cout<<"MMM BRAINS"<<endl;
	}
	return 0;
}
