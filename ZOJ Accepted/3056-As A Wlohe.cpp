#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map<string,string>	dict;
int main()
{
	char word[40];
	char sentence[100];
	string key,val;
	while(scanf("%s",word)){
		if(strcmp(word,"DICTIONARY_DEFINE_OVER")==0)	break;
		val=(string)word;
		if(strlen(word)>3)
			sort(word+1,word+strlen(word)-1);
		key=(string)word;
		dict[key]=val;
	}
	getchar();
	while(gets(sentence)){
		int len=strlen(sentence);
		for(int i=0,j;i<len;++i){
			if(sentence[i]<'a'||sentence[i]>'z')	continue;
			for(j=i+1;j<len&&sentence[j]>='a'&&sentence[j]<='z';++j)	;
			memset(word,'\0',40);
			for(int k=i;k<j;++k)
				word[k-i]=sentence[k];
//			printf("%s\n",word);
			if(strlen(word)>3)
				sort(word+1,word+strlen(word)-1);
			string rep = dict[string(word)];
//			printf("%s %d\n",rep.c_str(),rep.length());
			for(int k=i;k<j;++k)
				sentence[k]=rep[k-i];
			i=j-1;
		}
		printf("%s\n",sentence);
	}
	return 0;
}