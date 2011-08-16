#include<cstdio>
int gcd(int a,int b)
{
	if(b == 0)	return a;
	return gcd(b,a%b);
}
int num[500];
bool isprime[500][500];
int primes[498][501];
int notprimes[498][501];
int main()
{
	int n,i,j,k,count;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i)
			scanf("%d",&num[i]);
		for(i=0;i<n-1;++i){
			primes[i][0]=0;
			notprimes[i][0]=0;
			for(j=i+1;j<n;++j){
				if(num[i]>=num[j])
					isprime[i][j]=(gcd(num[i],num[j])==1);
				else
					isprime[i][j]=(gcd(num[j],num[i])==1);
//				printf("(%d,%d)=%d\n",i,j,isprime[i][j]);
//				isprime[j][i]=isprime[i][j];
				if(isprime[i][j])
					primes[i][++primes[i][0]]=j;
				else
					notprimes[i][++notprimes[i][0]]=j;
			}
		}
//		for(i=0;i<n-1;++i){
//			for(j=i+1;j<n;++j)
//				printf("(%d,%d)=%d ",i,j,isprime[i][j]);
//			printf("\n");
//		}

		count=0;
		for(i=0;i<n-2;++i)
			for(j=1;j<primes[i][0];++j)
				for(k=j+1;k<=primes[i][0];++k)
					if(isprime[primes[i][j]][primes[i][k]])
						++count;
		for(i=0;i<n-2;++i)
			for(j=1;j<notprimes[i][0];++j)
				for(k=j+1;k<=notprimes[i][0];++k)
					if(!isprime[notprimes[i][j]][notprimes[i][k]])
						++count;
		printf("%d\n",count);
	}
	return 0;
}
