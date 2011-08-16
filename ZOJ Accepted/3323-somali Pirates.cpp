#include <cstdio>
#include <cstring>
int main()
{
	int T;
	char password[24];
	scanf("%d",&T);
	while(T--){
		scanf("%s",password);
		int len=strlen(password);
		for(int i=0;i<len;++i)
			if(password[i]<'0'||password[i]>'9')
				putchar(password[i]);
		putchar('\n');
	}
	return 0;
}