#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int C;
	int grade[1000];
	cin>>C;
	while(C--){
		int N,i,num=0;
		double avg=0;
		cin>>N;
		for(i=0;i<N;i++){
			cin>>grade[i];
			avg+=grade[i];
		}
		avg/=N;
		for(i=0;i<N;i++)
			if(grade[i]>avg)	num++;
		double ans=double(num*100)/N;
		printf("%.3f%\n",ans);
	}
	return 0;
}
