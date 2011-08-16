#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 2147483647
int main()
{
	long long minx,miny,maxx,maxy;
	long long x,y;
	while(cin>>x>>y&&!(x==0&&y==0)){
		minx=MAX;miny=MAX;
		maxx=-MAX;maxy=-MAX;
		if(x<minx)	minx=x;
		if(x>maxx)	maxx=x;
		if(y<miny)	miny=y;
		if(y>maxy)	maxy=y;
		while(cin>>x>>y&&!(x==0&&y==0)){
			if(x<minx)	minx=x;
			else if(x>maxx)	maxx=x;
			if(y<miny)	miny=y;
			else if(y>maxy)	maxy=y;
		}
		printf("%lld %lld %lld %lld\n",minx,miny,maxx,maxy);
	}
	return 0;
}
