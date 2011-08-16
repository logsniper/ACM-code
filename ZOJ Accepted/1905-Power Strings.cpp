#include<cstdio>
#include<cstring>
using namespace std;

bool check(char word[],char part[])
{
	int wlen=strlen(word),plen=strlen(part);
	int k,i;
	for(k=0;k<wlen;k+=plen)
		for(i=0;i<plen;i++)
			if(word[k+i]!=part[i])	return 0;
	return 1;
}

int main()
{
	char word[1000001],part[1000001],c;
	int len,n,k,i;
	while(scanf("%c",&c)!=EOF&&c!='.'){
		word[0]=c;
		len=1;
		while(scanf("%c",&c)&&c!='\n')
			word[len++]=c;
		word[len]='\0';
//		printf("%d\n",strlen(word));
		n=1;
		strcpy(part,word);
		for(i=1;i<len;i++)
			if(word[i]==word[0]&&len%i==0){
				part[i]='\0';
				if(check(word,part)){
					n=len/i;
					break;
				}
				else
					part[i]=word[i];
			}
		printf("%d\n",n);
	}
	return 0;
}
