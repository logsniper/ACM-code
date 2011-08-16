#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char keyboard[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
	char c;
	int keyboard_len=strlen(keyboard);
	while(scanf("%c",&c)!=EOF){
		if(c==' '||c=='\n')	putchar(c);
		else{
			int i;
			for(i=0;i<keyboard_len;i++)
				if(c==keyboard[i]){
					putchar(keyboard[i-1]);
					break;
				}
		}
	}
	return 0;
}
