#include<iostream>
using namespace std;
int main()
{
	int s,d;
	int s0,d0;
	int n,i;
	bool flag[60];
	while(cin>>s>>d&&(s!=0||d!=0)){
		for(i=0;i<60;i++)
			flag[i]=0;
		s0=s;d0=d;
		d=d%60;
		n=0;
		while(s!=0){
			if(flag[s]==1)	break;
			flag[s]=1;
			s=s*(d+1);
			s=s%60;
			n++;
		}
		if(s==0)	cout<<n<<endl;
		else cout<<"Impossible\n";
	}
	return 0;
}
