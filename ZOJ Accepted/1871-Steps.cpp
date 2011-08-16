#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x,y,L;
	int n,Smax;
	while(scanf("%d%d",&x,&y)!=EOF){
		L=y-x;
		Smax=0;
		for(n=1;Smax<L;n++)
			if(n%2)		Smax+=n/2+1;
			else Smax+=n/2;
		n--;
		cout<<n<<endl;
	}
}
