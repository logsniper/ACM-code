#include<cstdio>
using namespace std;

typedef struct block{
	int x,y;
	block *next;
}BLOCK;

BLOCK *first,*last;
int x_total,y_total;
bool listed[100][100];
char oil[100][100];

void test(int x,int y)
{
	BLOCK *tmp;
	for(int yi=y-1;yi<=y+1;yi++)
		for(int xi=x-1;xi<=x+1;xi++){
			if(listed[yi][xi]==1||xi<0||yi<0)	continue;
			if(oil[yi][xi]=='@'){
				tmp=new(BLOCK);
				tmp->x=xi;
				tmp->y=yi;
				tmp->next=NULL;
				last->next=tmp;
				last=tmp;
				listed[yi][xi]=1;
			}
		}
	tmp=first;
	first=first->next;
	delete(tmp);
}

int main()
{
	int quantity;
	while(scanf("%d%d",&y_total,&x_total)&&!(x_total==0&&y_total==0)){
		int quantity=0;
		int xi,yi;
		for(yi=0;yi<y_total;yi++){
			scanf("%s",oil[yi]);
			for(xi=0;xi<x_total;xi++)
				listed[yi][xi]=0;
		}
		first=NULL;last=NULL;
		for(yi=0;yi<y_total;yi++)
			for(xi=0;xi<x_total;xi++){
				if(oil[yi][xi]=='@'&&listed[yi][xi]==0){
					quantity++;
//					printf("%d %d\n",xi,yi);
					first=new(BLOCK);
					first->x=xi;
					first->y=yi;
					first->next=NULL;
					last=first;
					listed[yi][xi]=1;
					while(first!=NULL)
						test(first->x,first->y);
				}
			}
		printf("%d\n",quantity);
	}
	return 0;
}
