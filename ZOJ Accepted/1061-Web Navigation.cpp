#include<cstdio>
#include<cstring>
using namespace std;
typedef struct LINE{
	char url[71];
	LINE *next;
	LINE *prev;
}LINE;
int main()
{
	int block;
	LINE *first,*last,*now,*tmp;
	char cmd[10];
	scanf("%d",&block);
while(block--){
	first=new(LINE);
	first->prev=NULL;
	first->next=NULL;
	strcpy(first->url,"http://www.acm.org/");
	now=first;
	last=first;
	while(scanf("%s",cmd)&&cmd[0]!='Q'){
		if(cmd[0]=='V'){
//			printf("%c : ",cmd[0]);
			while(last!=now){
				tmp=last;
				last=last->prev;
				last->next=NULL;
				delete(tmp);
			}
			now=new(LINE);
			now->prev=last;
			now->next=NULL;
			last->next=now;
			last=now;
			scanf("%s",now->url);
			printf("%s\n",now->url);
		}
		else if(cmd[0]=='F'){
//			printf("%c : ",cmd[0]);
			if(now!=NULL){
				if(now->next==NULL){
					printf("Ignored\n");
				}
				else{
					now=now->next;
					printf("%s\n",now->url);
				}
			}
		}
		else if(cmd[0]=='B'){
//			printf("%c : ",cmd[0]);
			if(now!=NULL){
				if(now->prev==NULL){
					printf("Ignored\n");
				}
				else{
					now=now->prev;
					printf("%s\n",now->url);
				}
			}
		}
		else if(cmd[0]=='Q'){
			for(now=first;now!=NULL;now=tmp){
				tmp=now->next;
				delete(now);
			}
			break;
		}
	}
	if(block)	printf("\n");
}
	return 0;
}
