#include<iostream>
#include<cstring>
using namespace std;
long long AmontInDigit(long long digit)
{
	if(digit<=2)	return 9;
	long long k=(digit+1)/2,ans=9;
	for(long long i=1;i<k;i++)
		ans*=10;
	return ans;
}

int main()
{
	long long number,NowAmount,NowDigit,n,i;
	char num[60];
	while(cin>>n&&n!=0){
		NowAmount=0;NowDigit=0;
		while(NowAmount<n){
			NowDigit++;
			NowAmount+=AmontInDigit(NowDigit);
		}
		NowAmount-=AmontInDigit(NowDigit);
		long long HalfDigit=(NowDigit+1)/2;
		for(number=1,i=1;i<HalfDigit;i++)
			number*=10;
		number+=(n-NowAmount-1);
		long long tmp=number;
		for(i=HalfDigit-1;i>=0;i--){
			num[i]=tmp%10+'0';
			tmp/=10;
		}
		if(NowDigit%2)	tmp=number/10;
		else tmp=number;
		for(i=HalfDigit;i<NowDigit;i++){
			num[i]=tmp%10+'0';
			tmp/=10;
		}
		num[NowDigit]='\0';
		cout<<num<<endl;
	}
	return 0;
}
