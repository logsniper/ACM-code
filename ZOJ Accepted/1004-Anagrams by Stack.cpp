#include<cstdio>
#include<string.h>
#define SIZE 1000
using namespace std;

int NextSeq(char io[],int n)
{
	int pi,po,j,k;
	pi=0;po=0;
	for(j=n-1;io[j]!='i'||po<=pi+1;j--){
		if(io[j]=='i')	pi++;
		else po++;
		if(j==0)	return 0;
	}
	io[j]='o';
	for(k=j+1;k<=j+2+pi-1;k++)	io[k]='i';
	for(;k<n;k++)	io[k]='o';
	return 1;
}

struct stack
{
	char ddd;
	stack *next;
};

struct stack *top,*bottom,*now;

void push(char c)
{
	if(top!=NULL){
		now=new(stack);
		now->ddd=c;
		now->next=top;
		top=now;
	}
	else{
		bottom=new(stack);
		bottom->ddd=c;
		bottom->next=NULL;
		top=bottom;
	}
}

char pop()
{
	char popout;
	now=top;
	top=top->next;
	popout=now->ddd;
	delete(now);
	return popout;
}

int main()
{
	char a[SIZE],b[SIZE],tmp[SIZE],io[SIZE*2];
	int n,ia,itmp,ispace;
	int i,flag;
	while(scanf("%s%s",a,b)!=EOF){
		n=strlen(a);
		for(i=0;i<n;i++)	io[i]='i';
		for(;i<n*2;i++)	io[i]='o';
		printf("[\n");
		do{
			flag=1;
			top=NULL;bottom=NULL;
			ia=0;itmp=0;
			for(i=0;i<n*2;i++){
				if(io[i]=='i')	push(a[ia++]);
				else tmp[itmp++]=pop();
			}
			for(itmp=0;itmp<n;itmp++)
				if(b[itmp]!=tmp[itmp]){
					flag=0;break;
				}

			if(flag){
				for(i=0;i<n*2;i++)
					printf("%c ",io[i]);	
				printf("\n");
			}
		}while(NextSeq(io,n*2));
		printf("]\n");
	}
	return 0;
}
