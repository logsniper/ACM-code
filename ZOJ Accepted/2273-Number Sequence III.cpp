#include<cstdio>
#include<string>
using namespace std;
int CountNNumber(int n)
{
	int res = 0;
	if(n<9){
		res=n;
		return res;
	}
	else	res+=9;
	if(n<99){
		res += (n-9)*2;
		return res;
	}
	else	res+=180;
	if(n<999){
		res += (n-99)*3;
		return res;
	}
	else	res+=2700;
	if(n<9999){
		res += (n-999)*4;
		return res;
	}
	else	res+=36000;
	
	res += (n-9999)*5;
	return res;
}
int GetTheLast(int n)
{
	int left = n,mod=1,rem=1,todel;
	bool delodd = false;
	while(left>1){
		int rem1=rem,rem2=rem+mod;
		if(delodd)	{rem = rem2;todel=rem1;}
		else 		{rem = rem1;todel=rem2;}
		mod*=2;
		int minus = n/mod;
		if(n%mod>=todel)	++minus;
		left -= minus;
		delodd = !delodd;
//		printf("%d %d %d\n",left,mod,rem);
	}
	return rem;
}
int main()
{
	int n;
	string seq;
	char num[8];
	for(int i=1;i<=99999;++i){
		sprintf(num,"%d",i);
		seq+=(string)num;
	}
	while(scanf("%d",&n)!=EOF){
		int len=CountNNumber(n);
		int respos=GetTheLast(len);
		printf("%c\n",seq[respos-1]);
	}
	return 0;
}
