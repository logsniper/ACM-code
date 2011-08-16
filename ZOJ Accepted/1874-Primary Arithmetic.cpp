#include<cstdio>
#include<cstring>
using namespace std;
typedef struct LargeNumber{
	char num[11];
}LargeNumber;

int plus_ln(LargeNumber a,LargeNumber b)
{
	int i,ans=0;
	class LargeNumber min=a,max=b,result;
	int len_min=strlen(a.num),len_max=strlen(b.num);
	for(i=0;i<len_max;i++){
		result.num[i]=max.num[len_max-1-i];
	}
	result.num[len_max]='\0';
	max=result;
	for(i=0;i<len_min;i++){
		result.num[i]=min.num[len_min-1-i];
	}
	result.num[len_min]='\0';
	min=result;
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
			ans++;
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
	
	return ans;
}

int main()
{
	LargeNumber a,b;
	while(scanf("%s%s",a.num,b.num)&&!(a.num[0]=='0'&&a.num[1]=='\0'&&b.num[0]=='0'&&b.num[1]=='\0')){
		int ans=plus_ln(a,b);
		if(ans==0)	printf("No carry operation.\n");
		else if(ans==1)	printf("1 carry operation.\n");
		else printf("%d carry operations.\n",ans);
	}
	return 0;
}
