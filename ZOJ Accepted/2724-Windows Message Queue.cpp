//STL优先队列是最大堆，与本题相反
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int number;
struct msg{
	char name[100];
	int value,prior;
	int clock;
	bool operator < (const msg &b) const
	{
		if( prior != b.prior )	return prior > b.prior;
		else		return clock>b.clock;
	}
	void operator = (const msg &b)
	{
		strcpy(name,b.name);
		value=b.value,prior=b.prior,clock=b.clock;
	}
};
// class PQ{
// private:
// 	msg q[60001];
// 	int size;
// public:
// 	bool empty()
// 	{
// 		if(size==0)	return true;
// 		else return false;
// 	}
// 	msg top()
// 	{
// 		return q[1];
// 	}
// 	void push(msg m)
// 	{
// 		int pos=++size;
// 		int father=pos/2;
// 		while(pos!=1&&m<q[father]){
// 			q[pos]=q[father];
// 			pos=father;
// 			father=pos/2;
// 		}
// 		q[pos]=m;
// 	}
// 	void pop()
// 	{
// 		msg m=q[size--];
// 		int pos=1,son=q[2]<q[3]?2:3;
// 		while(son<=size&&q[son]<m){
// 			q[pos]=q[son];
// 			pos=son;
// 			son*=2;
// 			if(son+1<=size&&q[son+1]<q[son])	++son;
// 		}
// 		q[pos]=m;
// 	}
// };
// PQ pq;
priority_queue <msg>	pq;//STL优先队列是最大堆，与本题相反
void get()
{
	if(pq.empty()){
		printf("EMPTY QUEUE!\n");
		return ;
	}
	printf("%s %d\n",pq.top().name,pq.top().value);
	pq.pop();
}
void put()
{
	msg tmp;
	scanf("%s%d%d",tmp.name,&tmp.value,&tmp.prior);
	tmp.clock=number++;
	pq.push(tmp);
}
int main()
{
	number=0;
	char order[8];
	while(scanf("%s",order)!=EOF){
		if(strcmp(order,"GET")==0)	get();
		else if(strcmp(order,"PUT")==0)	put();
	}
	return 0;
}