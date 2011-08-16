#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct LargeNumber{
	char num[1001];
}LargeNumber;

LargeNumber plus_ln(LargeNumber a,LargeNumber b)
{
	int i;
	class LargeNumber min=a,max=b,result;
	int len_min=strlen(a.num),len_max=strlen(b.num);
	if (len_min>len_max){
		min=b;
		max=a;
		int tmp=len_max;
		len_max=len_min;
		len_min=tmp;
	}
	
	for(i=len_min;i<len_max;i++)
		min.num[i]='0';
	min.num[len_max]='\0';
	
	int add=0;
	for(i=0;i<len_max;i++){
		int x=min.num[i]-'0',y=max.num[i]-'0';
		if(x+y+add>=10){
			result.num[i]='0'+x+y+add-10;
			add=1;
		}
		else{
			result.num[i]='0'+x+y+add;
			add=0;
		}
	}
	if(add==1){
		result.num[len_max]='1';
		result.num[len_max+1]='\0';
	}
	else	result.num[len_max]='\0';
	
	return result;
}

void print(LargeNumber a)
{
	int n=strlen(a.num);
	for(int i=n-1;i>=0;i--)
		printf("%c",a.num[i]);
	printf("\n");
}

int main()
{
	LargeNumber a,b,c;
	int k;
	while(cin>>k){
		a.num[0]='1';a.num[1]='\0';
		b.num[0]='1';b.num[1]='\0';
		if(k<=2)	print(b);
		else{
			for(int i=3;i<=k;i++){
				c=plus_ln(a,b);
				a=b;
				b=c;
			}
			print(b);
		}
	}
	return 0;
}
