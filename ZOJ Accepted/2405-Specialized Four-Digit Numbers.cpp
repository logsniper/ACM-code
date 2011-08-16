#include<iostream>
using namespace std;
int dgt_sum(int N,int base_k)
{
	int n=N;
	int sum=0;
	for(int i=0;n>0;i++){
		sum+=n%base_k;
		n/=base_k;
	}
	return sum;
}

int main()
{
	int N;
	for(N=2992;N<10000;N++){
		if(dgt_sum(N,10)==dgt_sum(N,12)&&dgt_sum(N,10)==dgt_sum(N,16))
			cout<<N<<endl;
	}
	return 0;
}
