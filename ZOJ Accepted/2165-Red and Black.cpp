#include<cstdio>
using namespace std;
typedef struct sq{
	int x,y;
	sq *next;
}SQUAREQUEUE;
int main()
{
	char square[20][21];
	bool visited[20][20];
	int M,H;
	int mi,hi;
	SQUAREQUEUE *start,*finish;
	while(scanf("%d%d",&M,&H)!=EOF&&!(M==0&&H==0))
	{
		int found=0;
		for(hi=0;hi<H;hi++){
			scanf("%s",square[hi]);
			for(mi=0;mi<M;mi++){
				visited[hi][mi]=0;
				if(found)	continue;
				if(square[hi][mi]=='@'){
					start=new(SQUAREQUEUE);
					start->y=hi;
					start->x=mi;
					start->next=NULL;
					finish=start;
					found=1;
				}
			}
		}
		SQUAREQUEUE *now=start;
		do{
			SQUAREQUEUE *tmp;
			int tmp_x=now->x,tmp_y=now->y;
			if(tmp_y<H-1&&visited[tmp_y+1][tmp_x]==0&&square[tmp_y+1][tmp_x]=='.'){
				tmp=new(SQUAREQUEUE);
				tmp->x=tmp_x;
				tmp->y=tmp_y+1;
				tmp->next=NULL;
				finish->next=tmp;
				finish=tmp;
				found++;
				visited[tmp_y+1][tmp_x]=1;
			}
			if(tmp_x<M-1&&visited[tmp_y][tmp_x+1]==0&&square[tmp_y][tmp_x+1]=='.'){
				tmp=new(SQUAREQUEUE);
				tmp->x=tmp_x+1;
				tmp->y=tmp_y;
				tmp->next=NULL;
				finish->next=tmp;
				finish=tmp;
				found++;
				visited[tmp_y][tmp_x+1]=1;
			}
			if(tmp_y>0&&visited[tmp_y-1][tmp_x]==0&&square[tmp_y-1][tmp_x]=='.'){
				tmp=new(SQUAREQUEUE);
				tmp->x=tmp_x;
				tmp->y=tmp_y-1;
				tmp->next=NULL;
				finish->next=tmp;
				finish=tmp;
				found++;
				visited[tmp_y-1][tmp_x]=1;
			}
			if(tmp_x>0&&visited[tmp_y][tmp_x-1]==0&&square[tmp_y][tmp_x-1]=='.'){
				tmp=new(SQUAREQUEUE);
				tmp->x=tmp_x-1;
				tmp->y=tmp_y;
				tmp->next=NULL;
				finish->next=tmp;
				finish=tmp;
				found++;
				visited[tmp_y][tmp_x-1]=1;
			}
			now=now->next;
			delete(start);
			start=now;
		}while(now!=NULL);
		printf("%d\n",found);
		
	}
	return 0;
}
