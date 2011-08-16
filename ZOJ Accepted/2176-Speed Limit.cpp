#include<iostream>
using namespace std;
int main()
{
	int n;
	int speed[13];
	int time[13];
	int way;
	cin>>n;
	while(n!=-1){
		way=0;
		speed[0]=0;
		time[0]=0;
		for(int i=1;i<=n;i++){
			cin>>speed[i]>>time[i];
			way+=speed[i]*(time[i]-time[i-1]);
		}
		cout<<way<<" miles"<<endl;
		cin>>n;
	}
	return 0;
}
