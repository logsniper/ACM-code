#include<iostream>
using namespace std;
int ans[501];
int tri(int n)
{
	if(n==1) return 1;
	int part1,part2,part3;
	if(ans[n-1])	part1=ans[n-1];
	else	part1=tri(n-1);
	part2=(n+1)*n/2;
	if(n%2)
		part3=(n*n-1)/4;
	else
		part3=n*(n-2)/4+n/2;
	ans[n]=part1+part2+part3;
	return ans[n];
}
int main()
{
	int n;
	for(int i=0;i<501;i++)
		ans[i]=0;
	while(cin>>n){
		cout<<tri(n)<<endl;
	}
	return 0;
}
