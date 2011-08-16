#include<cstdio>
#include<cstring>
using namespace std;
bool judge(char word[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
		if(word[i]-word[i+1]>=0)	return 0;
	return 1;
}
void next_word(char word[],int n)
{
	int k;
	char tmp;
	do{
		word[n-1]++;
		tmp=word[n-1];
		k=n-1;
		while(tmp>'z'&&k>0){
			word[k]-=26;
			word[k-1]++;
			k--;
			tmp=word[k];
		}
	}while(judge(word,n)==0);
}
int main()
{
	int n,i;
	char word[6],now[6];
	int number;
	while(scanf("%s",word)!=EOF){
		n=strlen(word);
		if(judge(word,n)==0){
			printf("0\n");
			continue;
		}
		for(i=0;i<n;i++)
			now[i]='a'+i;
		now[n]='\0';
		switch(n){
			case 1: number=1;break;
			case 2: number=27;break;
			case 3: number=352;break;
			case 4: number=2952;break;
			case 5: number=17902;break;
		}
		while(strcmp(now,word)<0){
			next_word(now,n);
			number++;
		}
		printf("%d\n",number);
	}
	return 0;
}
