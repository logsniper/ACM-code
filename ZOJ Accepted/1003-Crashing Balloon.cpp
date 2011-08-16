#include <iostream>
using namespace std;
inline bool isValid(long long n)
{
	for(int i=100;i>1&&n!=1;--i){
		if(n%i==0){
			n/=i;
		}
	}
	if(n!=1)	return false;
	else	return true;
}
bool dfs(long long x,long long y,int k)
{
	if(k>100)	return false;
//	cout<<x<<" "<<y<<" "<<k<<endl;
	if(x==1&&y==1)	return true;
	while(k<=100&&x%k!=0&&y%k!=0)	++k;
	if(x%k==0){
		if(dfs(x/k,y,k+1))
			return true;
	}
	if(y%k==0){
		if(dfs(x,y/k,k+1))
			return true;
	}
	if(dfs(x,y,k+1))
		return true;
	return false;
}

int main()
{
	long long x,y;
	while(cin>>x>>y){
		long long big=x>y?x:y;
		long long little=x+y-big;

		if(!isValid(little)){
			cout<<big<<endl;
		}
		else if(!isValid(big)){
			cout<<little<<endl;
		}
		else{
			if(dfs(big,little,2))
				cout<<big<<endl;
			else
				cout<<little<<endl;
		}
	}
	return 0;
}