#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	char sentence[1000];
	char word[100];
	int block,N,n,i,k,j;
	scanf("%d",&block);
	while(block--){
		scanf("%d",&N);
		getchar();
		while(N--){
			for(i=0;scanf("%c",sentence+i)&&sentence[i]!='\n';i++);
			sentence[i]='\0';
			n=strlen(sentence);
			for(i=0,j=0;i<=n;i++){
				if(sentence[i]!=' '&&sentence[i]!='\0'&&sentence[i]!='\n')
					word[j++]=sentence[i];
				else{
					word[j]='\0';
					k=strlen(word);
					for(j=k-1;j>=0;j--)	printf("%c",word[j]);
					if(i!=n)	printf(" ");
					word[0]='\0';
					j=0;
				}
			}
			printf("\n");
		}
		if(block)	printf("\n");
	}
	return 0;
}
