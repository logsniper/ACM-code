#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	float a,b,r1,r2;
	bool judge;
	while(scanf("%f%f%f%f",&a,&b,&r1,&r2)!=EOF){
		judge =0;
		if((a-r1-r2)*(a-r1-r2)+(b-r1-r2)*(b-r1-r2)>(r1+r2)*(r1+r2))
			judge=1;
		if(judge) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
