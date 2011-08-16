#include<cstdio>
#include <cstring>
long long myExp[20];
void calMyExp()
{
	myExp[0]=1;
	for(int i=1;i<19;++i){	myExp[i]=myExp[i-1]*10;}
};
inline long long q(long long start, long long N)
{
	if(start==0)	return 0;
	long long res = 0;
	char s[20],n[20];
	sprintf(s,"%lld",start);
	sprintf(n,"%lld",N);
	int diff=strlen(n)-strlen(s);
	for(int i=0;i<=diff;++i){
		long long low=start*myExp[i],up=(start+1)*myExp[i]-1;
		if(N>=low&&N<=up)	res+=N-low+1;
		else if(N>up)		res+=up-low+1;
	}
//	printf("%lld %lld %lld\n",N,start,res);
	return res;
}
inline long long Q(long long n,long long k)
{
	if(n<k)	return -1;
	long long res=0;
	long long start;
	char kk[20],kkk[20];
	sprintf(kk,"%lld",k);
	memset(kkk,'\0',sizeof(kkk));
	for(int i=0;i<strlen(kk);++i){
		for(int j='0';j<kk[i];++j){
			kkk[i]=j;
			sscanf(kkk,"%lld",&start);
			res+=q(start,n);
		}
		kkk[i]=kk[i];
		++res;
	}
	return res;
}

bool findN(long long &n,long long k,long long m)
{
	long long prevn=k;
	if(Q(k,k)>m)		return false;
	n=k;
	while(Q(n,k)<m){
		prevn=n;
		n*=2;
		if(n<=0)	return false;
	}
//	printf("%lld %lld\n",prevn,n);
	while(prevn<=n){
		long long mid=(prevn+n)/2;
		long long qq=Q(mid,k);
		if(qq==m&&Q(mid-1,k)<m){
			n=mid;return true;
		}
		else if(qq<m)	prevn=mid+1;
		else	n=mid-1;
	}
	return false;
}

int main()
{
	long long n,k,m;
	calMyExp();
	while(scanf("%lld%lld",&k,&m)!=EOF){
//		printf("%lld\n",Q(k,m));
		if(findN(n,k,m))	printf("%lld\n",n);
		else		printf("0\n");
	}
	return 0;
}