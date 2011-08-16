#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,n;
	int rope[1000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&rope[i]);
		sort(rope,rope+n);
		int max=0;
		for(int i=0;i<n;++i){
			int now=(n-i)*rope[i];
			if(now>max)	max=now;
		}
		printf("%d\n",max);
	}
	return 0;
}
