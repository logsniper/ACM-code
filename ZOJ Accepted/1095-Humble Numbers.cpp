#include<iostream>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int fuck[5844],k;

int NextSeq(int ep[])
{
	ep[0]++;
	if(ep[0]+ep[1]+ep[2]+ep[3]>30){
		ep[0]=0;
		ep[1]++;
	}
	if(ep[1]+ep[2]+ep[3]>19){
		ep[1]=0;
		ep[2]++;
	}
	if(ep[2]+ep[3]>13){
		ep[2]=0;
		ep[3]++;
	}
	if(ep[3]>11)	return 0;
	else return 1;
}


int main()
{
	int tmp;
	int i,flag;
	long long n;
	int ep[4];
	for(i=0;i<4;i++)	ep[i]=0;
	fuck[0]=0;	
	k=1;

	do{
//		cout<<ep[3]<<" "<<ep[2]<<" "<<ep[1]<<" "<<ep[0]<<endl;
		n=1;flag=1;
		for(i=0;i<ep[0];i++)	n*=2;
		for(i=0;i<ep[1]&&flag;i++){
			n*=3;
			if(n>2000000000)	flag=0;
		}
		for(i=0;i<ep[2]&&flag;i++)	{
			n*=5;
			if(n>2000000000)	flag=0;
		}
		for(i=0;i<ep[3]&&flag;i++)	{
			n*=7;
			if(n>2000000000)	flag=0;
		}
		if(n<=2000000000&&flag)	fuck[k++]=n;
	}while(NextSeq(ep));
	qsort(fuck,5843,4,comp);

	while(cin>>k&&k!=0){
		cout<<"The "<<k;
		if(k%100>10&&k%100<20)	cout<<"th";
		else switch(k%10){
			case 1:cout<<"st";break;
			case 2:cout<<"nd";break;
			case 3:cout<<"rd";break;
			default:cout<<"th";
		}
		cout<<" humble number is "<<fuck[k]<<".\n";
	}
	return 0;
}
