#include<cstdio>
using namespace std;
int main()
{
	int sum,n,i;
	char a[257];
	a[0]='0';
	for(i=1;a[i-1]!='\n';i++)	scanf("%c",a+i);
	while(a[1]!='#'){
		sum=0;
		n=i-2;
		for(i=0;i<=n;i++){
			if(a[i]!=' ')	sum+=i*(a[i]-'A'+1);
		}
		printf("%d\n",sum);
		for(i=1;a[i-1]!='\n';i++)	scanf("%c",a+i);
	}
	return 0;
}
