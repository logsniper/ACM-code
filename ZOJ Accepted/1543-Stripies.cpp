#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
using namespace std;
int comp(const void *a,const void *b)
{
	return int(*(double *)a-*(double *)b);
}
int main()
{
	int NUM;
	double stripies[100];
	while(cin>>NUM){
		for(int i=0;i<NUM;i++)
			cin>>stripies[i];
		qsort(stripies,NUM,sizeof(double),comp);
		for(int i=NUM-2;i>=0;i--){
			stripies[i]=2*sqrt(stripies[i]*stripies[i+1]);
		}
		printf("%.3f\n",stripies[0]);
	}
	return 0;
}
