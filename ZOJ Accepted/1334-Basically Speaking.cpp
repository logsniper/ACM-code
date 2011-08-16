#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char from[10],to[10];
	int from_base,to_base;
	int i,j,f,t,n,tmp;
	while(cin>>from>>from_base>>to_base){
		f=strlen(from);
		n=0;
		tmp=1;
		for(i=f-1;i>=0;i--,tmp*=from_base){
			if(from[i]>='A')	n+=(from[i]-'A'+10)*tmp;
			else	n+=(from[i]-'0')*tmp;
		}
		for(t=0;t<7&&n>=to_base;t++){
			tmp=n%to_base;
			if(tmp<=9)	to[t]='0'+tmp;
			else	to[t]='A'+tmp-10;
			n/=to_base;
		}
		if(n<=9)	to[t]='0'+n;
		else	to[t]='A'+n-10;
		if(t>=7)	cout<<"  ERROR\n";
		else{
			for(i=0;i<7-t-1;i++)	cout<<" ";
			for(i=t;i>=0;i--)	cout<<to[i];
			cout<<endl;
		}
//		cout<<n<<endl;
	}
	return 0;
}
