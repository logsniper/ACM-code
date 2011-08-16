#include<iostream>
#include<cstdio>
using namespace std;

double C(double n,double t)
{
	double u=1,v=1;
	for(double i=t+1;i<=n;i++)
		u*=i;
	for(double j=1;j<=n-t;j++)
		v*=j;
	return u/v;
}

int main()
{
	int N;
	int s[12];
	int i,j;
//	cin>>N;
	while(scanf("%d",&N)!=EOF&&N!=0){
		double sum=0,PQ=1;
		for(i=0;i<N;i++){
			cin>>s[i];
			sum+=s[i];
		}
		for(i=0;i<N;i++){
			int k=1,flag=0;
			for(j=0;j<i;j++)
				if(s[i]==s[j]) {flag++;break;}
			if(flag) continue;
			for(j=i+1;j<N;j++)
				if(s[i]==s[j]) k++;
			for(j=0;j<k;j++){
				PQ*=C(sum,s[i]);
				sum-=s[i];
			}
			for(j=2;j<=k;j++)
				PQ/=j;
		}
		cout<<PQ<<endl;
//		cin>>N;
	}
	return 0;
}
