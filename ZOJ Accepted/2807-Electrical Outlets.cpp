#include<cstdio>
using namespace std;
int main()
{
	int N,n,i;
	int a[20];
	int sum;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&n);
		sum=-n+1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
