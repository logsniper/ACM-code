#include<cstdio>
#include<cstring>
using namespace std;
int find(char c)
{
	if(c=='B'|| c=='F'|| c=='P'|| c=='V')	return 1;
	if(c=='C'|| c=='G'|| c=='J'|| c=='K'||c=='Q'|| c=='S'|| c=='X'|| c=='Z')	return 2;
	if(c=='D'|| c=='T')	return 3;
	if(c=='L')	return 4;
	if(c=='M'|| c=='N')	return 5;
	if(c=='R')	return 6;
	return 0;
}

int main()
{
	char word[21];
	while(scanf("%s",word)!=EOF){
		int len=strlen(word);
		int a=0,b,i;
		for(i=0;i<len;i++){
			b=find(word[i]);
			if(b==0||b==a){
				a=b;
				continue;
			}
			printf("%d",b);
			a=b;
		}
		printf("\n");
	}
	return 0;
}
