#include<iostream>
#include<cstdio>
using namespace std;

class sequence{
private:
	int a[5000];
public:
	int tmp_min;
	int n;
	int min;
	void input_a();
	int InversionNumber();
	void InversionNumber_easy();
	void move();
};

void sequence::input_a()
{
	for(int i=0;i<n;i++)
		cin>>a[i];
}

int sequence::InversionNumber()
{
	int k=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j]) k++;
	return k;
}

void sequence::InversionNumber_easy()
{
	tmp_min=tmp_min+(n-1-a[n-1])-(a[n-1]);
}

void sequence::move()
{
	int tmp=a[0];
	for(int i=0;i<n-1;i++)
		a[i]=a[i+1];
	a[n-1]=tmp;
}

int main()
{
	class sequence S;
	while((scanf("%d",&S.n))!=EOF){
		S.input_a();
		S.min=S.InversionNumber();
		S.tmp_min=S.min;
		for(int i=0;i<S.n;i++){
			S.move();
			S.InversionNumber_easy();
//			cout<<S.tmp_min<<endl;
			if(S.min>S.tmp_min) S.min=S.tmp_min;
		}
		cout<<S.min<<endl;
	}
	return 0;
}
