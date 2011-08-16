#include<cstdio>
#include<cstring>
#include <iostream>
#define MAX 1000000
using namespace std;
char rslt[MAX];
void Add(char a[],char b[])
{
	char *sht,*lng;
	int len_min=strlen(a),len_max=strlen(b);
	sht=a;lng=b;
	if(len_min>len_max){
		int tmp=len_min;
		len_min=len_max;
		len_max=tmp;
		sht=b;
		lng=a;
	}
	int i,add=0;
	for(i=0;i<len_min;i++){
		rslt[i]=(sht[i]-'0'+lng[i]-'0'+add)%10+'0';
		if(sht[i]+lng[i]+add-'0'-'0'>=10)	add=1;
		else add=0;
	}
	for(i=len_min;i<len_max;i++){
		rslt[i]=(lng[i]+add-'0')%10+'0';
		if(lng[i]+add-'0'>=10)	add=1;
		else add=0;
	}
	if(add==1){
		rslt[len_max]='1';
		rslt[len_max+1]='\0';
	}
	else	rslt[len_max]='\0';
}

int main()
{
	int N;
	char a[MAX],b[MAX];
	scanf("%d",&N);
	while(N--){
		scanf("%s%s",a,b);
		Add(a,b);
		int i=0,len=strlen(rslt);
		while(rslt[i]=='0')
			i++;
		for(;i<len;i++)
			putchar(rslt[i]);
		putchar('\n');
	}
	return 0;
}
