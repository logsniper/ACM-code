#include<iostream>
using namespace std;

int win[4],lose[4];

bool IsEnd()
{
	bool flag=1;
	for(int i=1;i<4;i++)
		if(win[i]!=0||lose[i]!=0)
			flag=0;
	return flag;
}

int main()
{
	int i;
	while(1){
		for(i=1;i<4;i++)
			cin>>win[i]>>lose[i];
		if(IsEnd())	break;
		int total=win[1]+lose[1];
		int diff=win[1]-lose[1]+win[2]-lose[2]+win[3]-lose[3];
		win[0]=(total-diff)/2;
		lose[0]=total-win[0];
		cout<<"Anna's won-loss record is "<<win[0]<<"-"<<lose[0]<<".\n";
	}
}
