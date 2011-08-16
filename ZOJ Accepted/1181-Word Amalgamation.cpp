#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct{
	char word[8];
	int flag[26];
}DICT;
int comp(const void *a,const void *b)
{
	return strcmp(((DICT*)a)->word,((DICT*)b)->word);
}
bool compare(int a[],int b[])
{
	int i;
	for(i=0;i<26;i++)
		if(a[i]!=b[i])	return 0;
	return 1;
}
int N;
int main()
{
	DICT dct[100];
	int i=0,j,len;
	char *finish="XXXXXX";
	while(scanf("%s",dct[i].word)){
		if(strcmp(finish,dct[i].word)==0)	break;
		for(j=0;j<26;j++)
			dct[i].flag[j]=0;
		len=strlen(dct[i].word);
		for(j=0;j<len;j++)
			dct[i].flag[dct[i].word[j]-'a']++;
		i++;
	}
	N=i;
	qsort(dct,N,sizeof(DICT),comp);
//	for(i=0;i<N;i++)
//		printf("%s\n",dct[i].word);
	
	char target[8];
	int flag_target[26];
	while(scanf("%s",target)){
		if(strcmp(finish,target)==0)	break;
		for(j=0;j<26;j++)
			flag_target[j]=0;
		len=strlen(target);
		for(j=0;j<len;j++)
			flag_target[target[j]-'a']++;
		bool find=0;
		for(i=0;i<N;i++)
			if(compare(flag_target,dct[i].flag)==1){
				printf("%s\n",dct[i].word);
				find=1;
			}
		if(!find)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}
