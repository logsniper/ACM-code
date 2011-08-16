#include<iostream>
using namespace std;
int main()
{
	int N,i;
	int peg;
	int max_ball[51];
	cin>>N;
	max_ball[0]=-1;
	for(i=1;i<=50;i++){
		if(i%2==0)	max_ball[i]=max_ball[i-1]+i;
		else max_ball[i]=max_ball[i-1]+i+1;
	}
	while(N--){
		cin>>peg;
		cout<<max_ball[peg]<<endl;
	}
	return 0;
}
