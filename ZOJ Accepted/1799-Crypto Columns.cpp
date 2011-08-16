#include<cstdio>
#include<cstring>
using namespace std;
char key[11];
char ciphertext[101];
char plaintext[101];
char plaintext2[101];
int order[10];
int main()
{
	while(true){
		scanf("%s",key);
		if(strcmp(key,"THEEND")==0)	break;
		scanf("%s",ciphertext);
		int len=strlen(key);
		int len2=strlen(ciphertext);
		int rows=len2/len;
		int k=0;
		for(int i=0;i<26;++i)
			for(int j=0;j<len;++j){
				if(key[j]==i+'A'){
//					printf("%c %d %d\n",key[j],j,k);
					order[j]=k;
					++k;
				}
			}
//		for(int i=0;i<len;++i)
//			printf("%d ",order[i]);
		for(int i=0;i<len;++i)
			for(int j=0;j<rows;++j)
				plaintext2[i*rows+j]=ciphertext[order[i]*rows+j];
		for(int i=0;i<len;++i)
			for(int j=0;j<rows;++j)
				plaintext[j*len+i]=plaintext2[i*rows+j];
		plaintext[len2]='\0';
		plaintext2[len2]='\0';
		printf("%s\n",plaintext);
	}
	return 0;
}
