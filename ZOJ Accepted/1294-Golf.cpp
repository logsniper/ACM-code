#include<iostream>
using namespace std;
int main()
{
	int par,hole,N=1;
	while (cin>>par>>hole&&par*hole!=0){
		cout<<"Hole #"<<N++<<endl;
		if(hole ==1){
			cout<<"Hole-in-one.\n";
			cout<<endl;
			continue;
		}
		else if(hole<=par-3){
			cout<<"Double Eagle.\n";
			cout<<endl;
			continue;
		}
		else{
			switch(hole-par){
				case -2 : cout<<"Eagle.\n";break;
				case -1 : cout<<"Birdie.\n";break;
				case 0 : cout<<"Par.\n";break;
				case 1 : cout<<"Bogey.\n";break;
				default : cout<<"Double Bogey.\n";break;
			}
		}
		cout<<endl;
	}
	return 0;
}
