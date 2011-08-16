#include<cstdio>
#include<cstring>
#define min(A,B) (A>B?B:A)
using namespace std;
typedef struct ANS{
	int common;
	int total_length;
}ANS;
ANS appx(char a[],char b[])
{
	int la=strlen(a),lb=strlen(b);
	ANS ans;
	ans.common=0;
	ans.total_length=la+lb;
	int k,i,common_tmp;
	for(k=0;k<la;k++){
		common_tmp=0;
		for(i=0;i<min(la-k,lb);i++){
			if(a[i+k]==b[i])	common_tmp++;
		}
		if(common_tmp>ans.common)	ans.common=common_tmp;
	}
	for(k=0;k<lb;k++){
		common_tmp=0;
		for(i=0;i<min(lb-k,la);i++){
			if(b[i+k]==a[i])	common_tmp++;
		}
		if(common_tmp>ans.common)	ans.common=common_tmp;
	}
	ans.common*=2;
	return ans;
}
int main()
{
	ANS ans;
	char a[100],b[100];
	int devide,k;
	while(scanf("%s",a)&&(a[0]!='-'||a[1]!='1')){
		scanf("%s",b);
		ans=appx(a,b);
		if(ans.common!=0&&ans.common!=ans.total_length){
			for(k=1;k<=min(ans.common,ans.total_length);k++)
				if(ans.common%k==0&&ans.total_length%k==0)
					devide=k;
			ans.common/=devide;
			ans.total_length/=devide;
			printf("appx(%s,%s) = %d/%d\n",a,b,ans.common,ans.total_length);
		}
		else
			printf("appx(%s,%s) = %d\n",a,b,ans.common/ans.total_length);
	}
	return 0;
}
