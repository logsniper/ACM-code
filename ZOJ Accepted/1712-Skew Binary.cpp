#include<cstdio>
#include<cstring>
using namespace std;

long elem(int num,int k)
{
	int i,ans=1;
	for(i=0;i<k;i++)
		ans*=2;
	ans=num*(ans-1);
	return ans;
}

int main()
{
	char num[32];
	while(scanf("%s",num)&&!(num[0]=='0'&&num[1]=='\0')){
		int len=strlen(num);
		long ans=0;
		for(int i=0;i<len;i++){
			ans+=elem(num[i]-'0',len-i);
		}
		printf("%ld\n",ans);
	}
	return 0;
}
