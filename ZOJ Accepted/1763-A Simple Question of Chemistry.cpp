#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	double now,prev,diff;
	prev=-999;
	while(cin>>now&&now!=999){
		if(prev!=-999){
			diff=now-prev;
			printf("%.2f\n",diff);
		}
		prev=now;
	}
	printf("End of Output");
}
