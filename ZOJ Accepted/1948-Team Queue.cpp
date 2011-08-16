#include <cstdio>
#include <cstring>
int myqueue[1000][1000];
int head[1000],tail[1000];
int teambelong[1000000];
int team;
bool TeamInQueue[1000];
struct TeamQueue{
	int teamid;
	struct TeamQueue *next;
};
struct TeamQueue *h,*t;
inline bool init()
{
	scanf("%d",&team);
	if(!team)	return false;
	memset(head,0,team*sizeof(int));
	memset(tail,0,team*sizeof(int));
	memset(TeamInQueue,0,team*sizeof(int));
	memset(teambelong,0,1000000*sizeof(int));
	int k,elem;
	for(int i=0;i<team;++i){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&elem);
			teambelong[elem]=i;
		}
	}
	h=NULL,t=NULL;
	return true;
}
inline void enqueue(int tgt)
{
	int tid=teambelong[tgt];
	myqueue[tid][tail[tid]]=tgt;
	tail[tid]=(tail[tid]+1)%1000;
	if(!TeamInQueue[tid]){
		struct TeamQueue *tmp=new(struct TeamQueue);
		tmp->teamid=tid;
		tmp->next=NULL;
		if(t!=NULL){
			t->next=tmp;
			t=tmp;
		}
		else{
			h=tmp,t=tmp;
		}
		TeamInQueue[tid]=true;
	}
}
inline void dequeue()
{
	if(h==NULL)	return;
	int tid=h->teamid;
	printf("%d\n",myqueue[tid][head[tid]]);
	head[tid]=(head[tid]+1)%1000;
	if(head[tid]==tail[tid]){
		if(h!=t){
			struct TeamQueue *tmp=h;
			h=h->next;
			delete(tmp);
		}
		else{
			delete(h);
			h=NULL,t=NULL;
		}
		TeamInQueue[tid]=false;
	}
}
inline void clear()
{
	while(h!=NULL){
		t=h;
		h=h->next;
		delete(t);
	}
	printf("\n");
}
int main()
{
	int cas=0;
//	freopen("input.txt","r",stdin);
	while(init()){
		printf("Scenario #%d\n",++cas);
		char command[12];
		int elem;
		while(1){
			scanf("%s",command);
			if(command[0]=='E'){
				scanf("%d",&elem);
				enqueue(elem);
			}
			else if(command[0]=='D'){
				dequeue();
			}
			else{
				clear();
				break;
			}
		}
	}

	return 0;
}