#include<iostream>
using namespace std;
typedef struct NUMBER{
	long long begin;
	int c;
	int num[6];
}NUMBER;
long long fill(NUMBER *number)
{
	long long k;
	int i;
	for(i=number->c,k=0;i>=1;k++){
		i/=10;
	}
//	cout<<k<<" ";
	for(i=k-1;i>=0;i--){
		number->num[i]=number->c%10;
		number->c/=10;
	}
	return number->begin+k;
}
int main()
{
	int t;
	long long k;
	int i,n;
	long long start,tmp;
	long long total;
	int left;
	NUMBER *number;
	number=new(NUMBER);
	cin>>t;
	while(t--){
		cin>>k;
		total=1;n=1;
		while(total<=k){
			tmp=total;
			if(n>=10000){
				total+=38889;
				total+=(n-9999)*5;
			}
			else if(n>=1000){
				total+=2889;
				total+=(n-999)*4;
			}
			else if(n>=100){
				total+=189;
				total+=(n-99)*3;
			}
			else if(n>=10){
				total+=9;
				total+=(n-9)*2;
			}
			else total+=n;
			n++;
		}
		n--;
		while(tmp<=k){
			for(i=1;i<=n&&tmp<=k;i++){
				start=tmp;
				number->begin=start;
				number->c=i;
				tmp=fill(number);
			}
			n++;
		}
		cout<<number->num[k-number->begin]<<endl;
	}
	delete(number);
	return 0;
}
