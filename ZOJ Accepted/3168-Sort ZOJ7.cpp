#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
/*
int comp(const void *a,const void *b)
{
	if(*(char*)a=='Z')	return -1;
	if(*(char*)b=='Z')	return 1;
	if(*(char*)a=='O')	return -1;
	if(*(char*)b=='O')	return 1;
	if(*(char*)a=='J')	return -1;
	if(*(char*)b=='J')	return 1;
	if(*(char*)a=='7')	return -1;
	if(*(char*)b=='7')	return 1;
	return 0;
}*/

int main()
{
	int num_Z,num_O,num_J,num_7;
	char word[1001];
	char other[1001];
	while(scanf("%s",word)!=EOF){
		int len=strlen(word);
		int i=0,j=0,num_Z=0,num_O=0,num_J=0,num_7=0;
		for(i=0;i<len;i++){
			if(word[i]=='Z')	num_Z++;
			else if(word[i]=='O')	num_O++;
			else if(word[i]=='J')	num_J++;
			else if(word[i]=='7')	num_7++;
			else{
				other[j++]=word[i];
			}
		}
		other[j]='\0';
		for(i=0;i<num_Z;i++)
			putchar('Z');
		for(i=0;i<num_O;i++)
			putchar('O');
		for(i=0;i<num_J;i++)
			putchar('J');
		for(i=0;i<num_7;i++)
			putchar('7');
		printf("%s\n",other);
	}
	return 0;
}
