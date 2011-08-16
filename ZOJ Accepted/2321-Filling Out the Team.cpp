#include<iostream>
using namespace std;

class player
{
private:
	float SlowSpeed,MinWeight,MinStrength;
	bool flag,Is[3];
public:
 	int input();
 	void judge();
 	void output();
};

int player::input()
{
	flag=0;
	cin>>SlowSpeed>>MinWeight>>MinStrength;
	if(SlowSpeed==0&&MinWeight==0&&MinStrength==0)	return 0;
	else return 1;
}

void player::judge()
{
	Is[0]=SlowSpeed<=4.5&&MinWeight>=150&&MinStrength>=200;
	Is[1]=SlowSpeed<=6.0&&MinWeight>=300&&MinStrength>=500;
	Is[2]=SlowSpeed<=5.0&&MinWeight>=200&&MinStrength>=300;	
}

void player::output()
{
	if(Is[0]==0&&Is[1]==0&&Is[2]==0)
		cout<<"No positions";
	else{
		if(Is[0]){
			cout<<"Wide Receiver";
			flag=1;
		}
		if(Is[1]){
			if(flag)	cout<<" ";
			cout<<"Lineman";
			flag=1;
		}
		if(Is[2]){
			if(flag)	cout<<" ";
			cout<<"Quarterback";
		}
	}
	cout<<endl;
}

int main()
{
	class player P;
	while(P.input()){
		P.judge();
		P.output();
	}
	return 0;
}
