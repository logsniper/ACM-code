#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int N;
	int length,left,num;
	char word[100],now;
	scanf("%d",&N);
	while(N--){
		scanf("%s",word);
		length=strlen(word);
		left=length;
		while(left!=0){
			for(num=0,now=word[length-left];now==word[length-left];left--){
				num++;
			}
			if(num>1)	printf("%d",num);
			printf("%c",now);
		}
		printf("\n");
	}
	return 0;
}
