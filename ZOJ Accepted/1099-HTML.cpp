#include <cstdio>
#include <cstring>

inline bool ischar(char k)
{
	if(k==' '||k=='\n'||k=='\t')
		return false;
	if(k=='<'||k=='>')
		return false;
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int CharsOfThisline=0;
	char thisword[160];
	char tmp[160];
	bool space=true;
	while(scanf("%s",tmp)!=EOF){
		int len=strlen(tmp);
		if(tmp[0]=='<'){
			if(tmp[1]=='b'){
				printf("\n");
			}
			else if(tmp[1]=='h'){
				if(CharsOfThisline)
				printf("\n");
				for(int i=0;i<80;++i)
					printf("-");
				printf("\n");
			}
			CharsOfThisline=0;
		}
		else if(len){
			if(CharsOfThisline&&len+CharsOfThisline<80){
				printf(" %s",tmp);
				CharsOfThisline+=len+1;
			}
			else if(CharsOfThisline){
				printf("\n%s",tmp);
				CharsOfThisline=len;
			}
			else{
				printf("%s",tmp);
				CharsOfThisline=len;
			}
		}
	}
	return 0;
}