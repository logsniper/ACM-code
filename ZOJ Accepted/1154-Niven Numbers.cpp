#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int N;
	int b,n,digit;
	char shit[100];
	int length,i,k,tmp;
	scanf("%d",&N);
	while(N--){
	while(scanf("%d",&b)&&b!=0){
		scanf("%s",shit);
		length=strlen(shit);
		digit=0;n=0;tmp=1;
		for(i=length-1;i>=0;i--){
			k=shit[i]-'0';
			n+=tmp*k;
			tmp*=b;
			digit+=k;
		}
		if(n%digit==0)	printf("yes\n");
		else printf("no\n");
		
	}
		if(N!=0)	printf("\n");
	}
	return 0;
}
