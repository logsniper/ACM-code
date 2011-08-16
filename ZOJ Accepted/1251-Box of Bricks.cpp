//#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,i;
	int stack[50];
	int sum,avg;
	int k=1;
	while(scanf("%d",&n)&&n!=0){
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&stack[i]);
			sum+=stack[i];
		}
		avg=sum/n;
		sum=0;
		for(i=0;i<n;i++)
			if(stack[i]>avg) sum+=stack[i]-avg;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k++,sum);
	}
	return 0;
}
