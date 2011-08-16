#include<cstdio>
#include<cmath>

int digitsum(int n)
{
	int sum=0;
	while(n>=1){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

bool IsPrime(int n)
{
	if(n<=1)	return false;
	if(n==2||n==3)	return true;
	int k=(int)sqrt(n),i;
	for(i=2;i<=k;i++)
		if(n%i==0)	return false;
	return true;
}

bool judge(int n)
{
	int left=digitsum(n),right=0;
	int i;
	for(i=2;i<=n;i++)
		if(n%i==0){
			int k=0;
			while(n%i==0){
				k++;
				n/=i;
			}
			right+=k*digitsum(i);
			if(IsPrime(n)){
				right+=digitsum(n);break;
			}
		}
	if(left==right)	return true;
	else return false;
}

int findans(int n)
{
	int ans=n;
	while(ans++){
		if(IsPrime(ans))	continue;
		if(judge(ans))	return ans;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int ans=findans(n);
		printf("%d\n",ans);
	}
	return 0;
}
