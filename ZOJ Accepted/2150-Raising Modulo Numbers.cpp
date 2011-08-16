#include<cstdio>
using namespace std;
int left[33];
int modulo(int A,int B,int M)
{
	int a=A%M;
	left[1]=a;
	long long i,ans=1;
	for(i=2;i<33;i++)
		left[i]=(left[i-1]*left[i-1])%M;
	for(i=1;B>0;i++){
		if(B%2)	ans=(long long)(ans*left[i])%M;
		B/=2;
	}
	ans=ans%M;
	return ans;
}
int main()
{
	int Z,M,H,A,B,sum;
	scanf("%d",&Z);
	while(Z--){
		scanf("%d%d",&M,&H);
		sum=0;
		while(H--){
			scanf("%d%d",&A,&B);
			sum+=modulo(A,B,M);
		}
		sum=sum%M;
		printf("%d\n",sum);
	}
	return 0;
}
