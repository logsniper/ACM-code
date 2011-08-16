#include<iostream>
#include<cstdio>
#define SIZE 1000
using namespace std;

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

void pop()
{
	now=top;
	top=top->next;
	delete(now);
}

int main()
{
	char a[SIZE],b[SIZE];
	char stck[SIZE*2];
	int n,ia,ib,istck,ispace;
	bool flag;
	while(scanf("%s%s",a,b)!=EOF){
		top=NULL;bottom=NULL;
		ib=0;istck=0;
		flag=0;
		n=strlen(a);
		for(ia=0;ia<n;ia++){
			push(a[ia]);
			stck[istck++]='i';
			while(top!=NULL&&top->ddd==b[ib]){
				pop();
				stck[istck++]='o';
				ib++;
			}
		}
		if(b[ib]=='\0'&&ib==n) flag=1;
		printf("[\n");
		if(flag){
			ispace=1;
			for(istck=0;istck<n*2;istck++){
				printf("%c",stck[istck]);
				if(ispace++<n*2)	printf(" ");				
			}
			printf("\n");
		}
		printf("]\n");
	}
	return 0;
}
