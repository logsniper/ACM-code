#include<cstdio>
#include<cstring>
#define MAX 1000000
using namespace std;
int main()
{
	char s[MAX],t[MAX];
	while(scanf("%s%s",s,t)!=EOF){
		int slen=strlen(s);
		int tlen=strlen(t);
		int si,ti;
		bool flag=1;
		for(si=0,ti=0;si<slen;si++){
			while(ti<tlen)
				if(s[si]==t[ti++])	break;
			if(ti==tlen&&si<=slen-1&&s[si]!=t[ti-1]){
				flag=0;
				break;
			}
		}
		if(flag)	printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
