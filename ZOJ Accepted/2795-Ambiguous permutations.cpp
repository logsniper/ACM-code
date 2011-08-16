#include<iostream>
using namespace std;
int judge(int a[],int n)
{
	int i,j;
	for(i=1;i<=n;i++){
		j=a[i];
		if(a[j]!=i)	return 0;
	}
	return 1;
}

int main()
{
	int n,i;
	int a[100000];
	a[0]=0;
	while(cin>>n&&n!=0){
		for(i=1;i<=n;i++)	cin>>a[i];
	if(judge(a,n))	cout<<"ambiguous"<<endl;
	else cout<<"not ambiguous"<<endl;
	}
}
