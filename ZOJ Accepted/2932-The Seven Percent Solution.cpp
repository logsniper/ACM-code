#include<cstdio>
using namespace std;

void encode(char a[],int n)
{
	int i;
	for(i=0;i<n;i++){
		if(a[i]==' ')	printf("%%20");
		else if(a[i]=='!')	printf("%%21");
		else if(a[i]=='$')	printf("%%24");
		else if(a[i]=='%')	printf("%%25");
		else if(a[i]=='(')	printf("%%28");
		else if(a[i]==')')	printf("%%29");
		else if(a[i]=='*')	printf("%%2a");
		else printf("%c",a[i]);
	}
	printf("\n");
}

int main()
{
	int i;
	char a[80];
	int n;
	for(i=0;scanf("%c",a+i)&&a[i]!='\n';i++);
	while(a[0]!='#'){
		n=i;
		encode(a,n);
		for(i=0;scanf("%c",a+i)&&a[i]!='\n';i++);
	}
}
