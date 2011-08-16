#include<cstdio>
using namespace std;
typedef struct card{
	int element;
	card *next;
}CARD;
CARD* init(CARD paper[],int n)
{
	int i;
	for(i=n;i>=1;i--){
		paper[i].element=i;
		paper[i].next=&paper[i-1];
	}
	paper[1].next=NULL;
	card *first=&paper[n],*now;
	
//	for(now=first;now!=NULL;now=now->next)
//		printf("%d ",now->element);
//	printf("\n");
	return first;
}
CARD* operate(CARD paper[],CARD *first,int p,int c)
{
	CARD *now,*before_remove=NULL,*first_remove=NULL,*last_remove=NULL,*after_remove=NULL;
	int i;

	for(i=1,now=first;i<p-1;i++)
		now=now->next;
	if(p>1){
		before_remove=now;
		first_remove=now->next;
	}
	else first_remove=now;

	for(i=1,now=first_remove;i<c;i++)
		now=now->next;
	last_remove=now;
	after_remove=now->next;

	if(before_remove!=NULL)
		before_remove->next=after_remove;
	if(first==first_remove)
		first=after_remove;
	last_remove->next=first;
	first=first_remove;

//	for(now=first;now!=NULL;now=now->next)
//		printf("%d ",now->element);
//	printf("\n");
	return first;
}
int main()
{
	CARD paper[51],*first;
	int n,r,p,c;
	while(scanf("%d%d",&n,&r)&&!(n==0&&r==0)){
		first=init(paper,n);
		while(r--){
			scanf("%d%d",&p,&c);
			first=operate(paper,first,p,c);
		}
		printf("%d\n",first->element);
	}
	return 0;
}
