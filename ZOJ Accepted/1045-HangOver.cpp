#include<iostream>
using namespace std;

class HangOver
{
private:
	float sum;
	int n;
public:
	int input();
	void output();	
};

int HangOver::input()
{
	cin>>sum;
	if(sum==0) 
		return 0;
	else if(sum<0||sum>5.2)
		cout<<"input wrong!"<<endl;
	else return 1;
}

void HangOver::output()
{
	float s=0;
	int i;
	for(i=2;s<=sum;i++)
		s+=(float)1/i;
	n=i-2;
	cout<<n<<" card(s)"<<endl;
}

int main()
{
	class HangOver sp;
	while(sp.input())
		sp.output();
}
