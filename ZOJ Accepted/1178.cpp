#include<iostream>
#include<cstdio>
using namespace std;

class Booklet
{
private:
	int n;
	int sheet[25][4];
public:
	int input();
	void generate();
	void output();
};

int Booklet::input()
{
	cin>>n;
	if(n>0) return 1;
	else return 0;
}

void Booklet::generate()
{
	if(n%4==0)
		for(int i=0;i<(n+3)/4;i++){
			sheet[i][0]=n-2*i;
			sheet[i][1]=2*i+1;
			sheet[i][2]=sheet[i][1]+1;
			sheet[i][3]=sheet[i][0]-1;
		}
	if(n%4==1){
		for(int i=1;i<(n+3)/4;i++){
			sheet[i][0]=n-2*i+3;
			sheet[i][1]=2*i+1;
			sheet[i][2]=sheet[i][1]+1;
			sheet[i][3]=sheet[i][0]-1;
		}
		sheet[1][3]=n;
	}
	if(n%4==2)
		for(int i=1;i<(n+3)/4;i++){
			sheet[i][0]=n-2*i+2;
			sheet[i][1]=2*i+1;
			sheet[i][2]=sheet[i][1]+1;
			sheet[i][3]=sheet[i][0]-1;
		}
	if(n%4==3){
		for(int i=0;i<(n+3)/4;i++){
			sheet[i][0]=n-2*i+1;
			sheet[i][1]=2*i+1;
			sheet[i][2]=sheet[i][1]+1;
			sheet[i][3]=sheet[i][0]-1;
		}
		sheet[0][3]=n;
	}
}

void Booklet::output()
{
	int flag=1;
	cout<<"Printing order for "<<n<<" pages:"<<endl;
	switch(n%4){
		case 1:	cout<<"Sheet 1, front: Blank, 1"<<endl;
				if(n!=1){
					cout<<"Sheet 1, back : 2, Blank"<<endl;
					cout<<"Sheet 2, front: Blank, "<<sheet[1][1]<<endl;
					cout<<"Sheet 2, back : "<<sheet[1][2]<<", "<<sheet[1][3]<<endl;
					flag=2;
				}break;
		case 2:	cout<<"Sheet 1, front: Blank, 1"<<endl;
				cout<<"Sheet 1, back : 2, Blank"<<endl;break;
		case 3:	cout<<"Sheet 1, front: Blank, 1"<<endl;
				cout<<"Sheet 1, back : 2, "<<sheet[0][3]<<endl;break;
		case 0:flag=0;
	}
	for(int i=flag;i<(n+3)/4;i++){
		cout<<"Sheet "<<i+1<<", front: "<<sheet[i][0]<<", "<<sheet[i][1]<<endl;
		cout<<"Sheet "<<i+1<<", back : "<<sheet[i][2]<<", "<<sheet[i][3]<<endl;
	}
}

int main()
{
	class Booklet book;
//	freopen("1178out.txt","w",stdout);
	while(book.input()){
		book.generate();
		book.output();
	}
	return 0;
}
