#include<cstdio>
#include<cstring>
using namespace std;
void reverse(char a[],int n)
{
	int i;
	char c[101];
	for(i=0;i<n;i++)
		c[i]=a[n-1-i];
	for(i=0;i<n;i++)
		a[i]=c[i];
}
int main()
{
	char a[101],b[101],result[102];
	int n,m,k,c;
	int i,upto;
	while(scanf("%s%s",a,b)!=EOF){
		n=strlen(a);m=strlen(b);
		reverse(a,n);reverse(b,m);
		upto=0;
		for(i=0;i<n||i<m;i++){
			c=0;
			if(i<n)	{
				if(a[i]<='9'&&a[i]>='0')	c=a[i]-'0';
				else if(a[i]>='a'&&a[i]<='j')	c=a[i]-'a'+10;
			}
			if(i<m) {
				if(b[i]<='9'&&b[i]>='0')	c+=b[i]-'0';
				else if(b[i]>='a'&&b[i]<='j')	c+=b[i]-'a'+10;
			}
			c+=upto;
			if(c>=20){
				upto=1;
				c-=20;
			}
			else upto=0;
			if(c<10)	result[i]='0'+c;
			else if(c>=10&&c<20)	result[i]='a'+c-10;
		}
		if(upto){
			result[i]='1';
			result[i+1]='\0';
		}
		else	result[i]='\0';
		k=strlen(result);
		for(i=k-1;i>=0;i--)
			printf("%c",result[i]);
		printf("\n");
	}
	return 0;
}
