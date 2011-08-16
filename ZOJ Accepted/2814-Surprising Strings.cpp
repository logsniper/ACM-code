#include<iostream>
#include<string.h>
using namespace std;
int judge(char a[],int n,int D)
{
	char b[78][3];
	int i,j;
	for(i=0;i<n-D-1;i++){
		b[i][0]=a[i];
		b[i][1]=a[i+D+1];
		b[i][2]='\0';
	}
	for(i=0;i<n-D-1;i++)
		for(j=i+1;j<n-D-1;j++){
			if(strcmp(b[i],b[j])==0)	return 0;
		}
	return 1;
}

int main()
{
	char a[79];
	int D,i,n;
	int flag;
	while(cin>>a&&a[0]!='*'){
		flag=1;
		n=strlen(a);
		for(D=0;D<n-1;D++){
			if(judge(a,n,D)==0)	flag=0;
		}
		cout<<a<<" is ";
		if(!flag)	cout<<"NOT ";
		cout<<"surprising."<<endl;
	}
	return 0;
}
