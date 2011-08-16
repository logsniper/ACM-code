#include<iostream>
#include<string>
#define	Top 0
#define Bottom 1
#define North 2
#define South 3
#define West 4
#define East 5
using namespace std;
int state[6];

void init()
{
	state[Top]=1;
	state[North]=2;
	state[West]=3;
	state[East]=4;
	state[South]=5;
	state[Bottom]=6;
}

void roll(string dir)
{
	if(dir=="north"){
		int tmp=state[Top];
		state[Top]=state[South];
		state[South]=state[Bottom];
		state[Bottom]=state[North];
		state[North]=tmp;
	}
	else if(dir=="south"){
		int tmp=state[Top];
		state[Top]=state[North];
		state[North]=state[Bottom];
		state[Bottom]=state[South];
		state[South]=tmp;
	}
	else if(dir=="west"){
		int tmp=state[Top];
		state[Top]=state[East];
		state[East]=state[Bottom];
		state[Bottom]=state[West];
		state[West]=tmp;
	}
	else if(dir=="east"){
		int tmp=state[Top];
		state[Top]=state[West];
		state[West]=state[Bottom];
		state[Bottom]=state[East];
		state[East]=tmp;
	}
}

int main()
{
	int n;
	string dir;
	while(cin>>n&&n>0){
		init();
		for(int i=0;i<n;++i){
			cin>>dir;
			roll(dir);
		}
		cout<<state[Top]<<endl;
	}
	return 0;
}
