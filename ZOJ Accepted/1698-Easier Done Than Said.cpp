#include<cstring>
#include<cstdio>
using namespace std;

bool IsVowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;
	else return 0;
}

int main()
{
	char word[30];
	int i;
	while(scanf("%s",word)&&strcmp(word,"end")!=0){
		int length=strlen(word);
		bool flag1=0,flag2=1,flag3=1;

		for(i=0;i<length;i++)
			if(IsVowel(word[i])){
				flag1=1;
				break;
			}
		if(flag1==0){
			printf("<%s> is not acceptable.\n",word);
			continue;
		}

		for(i=0;i<length-2;i++){
			int tmp=IsVowel(word[i])+IsVowel(word[i+1])+IsVowel(word[i+2]);
			if(tmp==0||tmp==3){
				flag2=0;
				break;
			}
		}
		if(flag2==0){
			printf("<%s> is not acceptable.\n",word);
			continue;
		}

		for(i=0;i<length-1;i++){
			if(word[i]==word[i+1]&&word[i]!='e'&&word[i]!='o'){
				flag3=0;
				break;
			}
		}
		if(flag3==0){
			printf("<%s> is not acceptable.\n",word);
			continue;
		}
		
		printf("<%s> is acceptable.\n",word);
	}
	return 0;
}
