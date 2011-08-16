#include<iostream>
#include<cstdio>
using namespace std;

class puzzle
{
private:
	char start[11];
	char fuck[1000];
	char end[4];
public:
	int ReadStart();
	void ReadFuck();
	void ReadEnd();
	void output();
};

int puzzle::ReadStart()
{
	int i=0;
	int flag=0;
	char END[11]={"ENDOFINPUT"};
	do{
		scanf("%c",&start[i]);
		}while(start[i++]!='\n');
	for(i=0;i<10;i++)
		if(start[i]!=END[i])	flag=1;
	return flag;
}

void puzzle::ReadFuck()
{
	int i=0;
	do{
		scanf("%c",&fuck[i]);
		}while(fuck[i++]!='\n');
}

void puzzle::ReadEnd()
{
	int i=0;
	do{
		scanf("%c",&end[i]);
		}while(end[i++]!='\n');
}

void puzzle::output()
{
	for(int i=0;fuck[i]!='\n';i++){
		if(fuck[i]>='A'&&fuck[i]<='E') fuck[i]+=21;
		else if(fuck[i]>='F'&&fuck[i]<='Z') fuck[i]-=5;
		printf("%c",fuck[i]);
	}
	printf("\n");
}


int main()
{	
	class puzzle shit;
	while(shit.ReadStart()){
		shit.ReadFuck();
		shit.ReadEnd();
		shit.output();
	}
	return 0;
}
