#include<cstdio>
#include<cstring>
using namespace std;
char dict[100][68];
bool NewLine;
bool search(char tgt[],char source[])
{
	int len_tgt=strlen(tgt);
	int len_source=strlen(source);
	if(len_tgt>len_source+1)	return 0;
	int poisition_star,i;
	for(poisition_star=0;tgt[poisition_star]!='*'&&poisition_star<len_tgt;poisition_star++)
		if(tgt[poisition_star]!=source[poisition_star])	return 0;
	if(poisition_star==len_tgt&&len_source!=len_tgt)	return 0;
	for(i=0;i<len_tgt-poisition_star;i++)
		if(tgt[len_tgt-i]!=source[len_source-i])	return 0;
	return 1;
}
void search2(char tgt[],int dict_num)
{
	int i;
	bool comma=0;
	for(i=0;i<dict_num;i++){
		if(search(tgt,dict[i])==1){
			if(comma)	printf(", ");
			else comma=1;
			printf("%s",dict[i]);
		}
	}
	if(!comma)	printf("FILE NOT FOUND");
}
int main()
{
	int N,M,i;
	char tgt[68];
	NewLine=0;
	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++)
			scanf("%s",dict[i]);
		scanf("%d",&M);
		if(NewLine)	printf("\n\n");
		else NewLine=1;
		while(M--){
			scanf("%s",tgt);
			search2(tgt,N);
			if(M)
				printf("\n");
		}
	}
	return 0;
}
