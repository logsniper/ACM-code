#include<iostream>
#include<cstdio>
using namespace std;

typedef struct color
{
	char name[16];
	int number;
	color *next;
}COLOR;

int main()
{
	int N;
	COLOR *last,*head,*now;
	char nm[16];
	COLOR pMax;
	while(scanf("%d",&N)&&N!=0){
		pMax.number=0;
		*pMax.name='\0';
		head=new(COLOR);
		*head->name='\0';
		head->number=0;
		last=head;
		for(int i=0;i<N;i++){
			scanf("%s",nm);
			for(now=head;now!=last->next;now=now->next){
				if(*(now->name)==*nm){
					now->number++;
					break;
				}				
			}
			if(now==last->next){
				now=new(COLOR);
//				now->name=nm;
				strcpy(now->name,nm);
				now->number=1;
				last->next=now;
				last=now;
			}
		}
		for(now=head;now!=last->next;now=now->next){
			if(pMax.number<now->number)		pMax=*now;
		}
		printf("%s\n",pMax.name);
	}
	return 0;
}
