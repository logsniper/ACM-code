#include<iostream>
using namespace std;

class Financial
{
public:
	float num[12];
	float avg();
};

float Financial::avg()
{
	float sum=0;
	for(int i=0;i<12;i++){

		sum+=num[i];
	}
	return sum/12;
}

int main()
{
	class Financial temp;
	
	for (int i=0;i<12;i++)
		cin>>temp.num[i];
	cout<<"$"<<temp.avg();
	
	return 0;	
}
