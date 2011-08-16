#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 500
#define INF 100000000
int graph[MAXN][MAXN];
int number;

int find(int father[],int child)
{
	int head=child;
	while(father[head]!=head)	head=father[head];
	while(father[child]!=child){
		int ft=father[child];
		father[child]=head;
		child=ft;
	}
	return child;
}
void Union(int father[],int a,int b)
{
	int A=find(father,a),B=find(father,b);
	if(A==B)	return;
	father[B]=A;
}

struct Way{
	int a,b;
	int dist;
	bool operator < (const struct Way &it) const{
		return dist>it.dist;
	}
	void operator = (const struct Way &it){
		a=it.a;
		b=it.b;
		dist=it.dist;
	}
};
int Kruskal()
{
	priority_queue<struct Way>	Q;
	int father[MAXN];
	for(int i=0;i<number;++i)
		for(int j=i+1;j<number;++j){
			if(graph[i][j]==INF)	continue;
			struct Way tmp;
			tmp.a=i;tmp.b=j;tmp.dist=graph[i][j];
			Q.push(tmp);
		}
	for(int i=0;i<number;++i)
		father[i]=i;
	int ret=0;
	while(!Q.empty()){
		struct Way now=Q.top();
		Q.pop();
		if(find(father,now.a)!=find(father,now.b)){
//			printf("%d %d %d\n",now.a,now.b,now.dist);
			ret+=now.dist;
			Union(father,now.a,now.b);
		}
	}
	return ret;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int test;
	scanf("%d",&test);
	while(test--){
		int edge;
		scanf("%d%d",&number,&edge);
		int a,b,dist;
		for(int i=0;i<number;++i)
			for(int j=0;j<number;++j)
				graph[i][j]=INF;
		while(edge--){
			scanf("%d %d %d",&a,&b,&dist);
			graph[a][b]=dist;
			graph[b][a]=dist;
		}
		int res=Kruskal();
		printf("%d\n",res);
	}
	return 0;
}