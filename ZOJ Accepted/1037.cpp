#include<iostream>
using namespace std;
class Gridland{
private:
	int m,n;
public:
	void input();
	void output();
};

void Gridland::input()
{
	cin>>m>>n;
}

void Gridland::output()
{
	if(m*n%2==0)
		cout<<m*n<<".00"<<endl<<endl;
	else
		cout<<m*n<<".41"<<endl<<endl;
}

int main()
{
	int N;
	class Gridland grid[10000];
	cin>>N;
	for(int i=0;i<N;i++)
		grid[i].input();
	for(int i=0;i<N;i++)
	{
		cout<<"Scenario #"<<i+1<<":"<<endl;
		grid[i].output();
	}
}
