#include<cstdio>
#include<iostream>
using namespace std;

/*
long long f(int n,int k)
{
	long long s=0;
	if(k>n*(n-1)/2||k<0) return 0;
	else if(n==1) return 1;
	else {
		for(int i=k-n+1;i<=k;i++){
			s+=f(n-1,i);
		}
		return s;
	}
}*/


int main()
{
	int n,k;
	long long s;
	long long a[21][201];
	for(n=1;n<=20;n++){
		for(k=0;k<=200;k++){
			if(k>(n*(n-1)/2)) a[n][k]=0;
			else if(n==1) a[n][k]=1;
			else {
				s=0;
				for(int i=((k-n+1)>0?(k-n+1):0);i<=k;i++){
					s+=a[n-1][i];
				}
				a[n][k]= s;
			}
		}
	}
	while(scanf("%d%d",&n,&k)&&(n!=0||k!=0)){
//		cout<<a[n][k]<<endl;
		printf("%lld\n",a[n][k]);
	}
	return 0;
}
