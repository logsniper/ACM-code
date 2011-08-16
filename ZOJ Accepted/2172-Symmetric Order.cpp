#include<cstdio>
using namespace std;
int main()
{
	char name[15][28];
	int n,set=0;
	while(scanf("%d",&n)&&n!=0){
		set++;
		int i;
		for(i=0;i<n;i++)
			scanf("%s",name[i]);
		printf("SET %d\n",set);
		for(i=0;i<=n-1;i+=2)
			printf("%s\n",name[i]);
		int first;
		if(n%2)	first=n-2;
		else first=n-1;
		for(i=first;i>=1;i-=2)
			printf("%s\n",name[i]);
	}
	return 0;
}
