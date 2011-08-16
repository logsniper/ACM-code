#include<cstdio>
#include<cstdlib>
typedef struct {
	int a,b;
}problem;
int comp(const void *x,const void *y)
{
	int ret = ((problem*)x)->a-((problem*)y)->a;
	if(!ret)
		ret = ((problem*)y)->b-((problem*)x)->b;
	return ret;
}
problem prb[100000];
int heapb[100001];
int n,heapsize;

bool insertheap(int elem)
{
	if(heapsize==100000)	return false;
	++heapsize;
	int i;
	for(i=heapsize;i>1;i/=2){
		if(heapb[i/2]<elem)
			heapb[i]=heapb[i/2];
		else	break;
	}
	heapb[i]=elem;
	return true;
}

int deleteheap()
{
	if(heapsize==0)	return -1;
	int ret=heapb[1],lastelem=heapb[heapsize],i,maxchild=1;
	for(i=1;i<=heapsize;i=maxchild){
		if(i*2>heapsize)	break;
		maxchild=i*2;
		if(maxchild<heapsize&&heapb[maxchild]<heapb[maxchild+1])
			++maxchild;
		heapb[i]=heapb[maxchild];		
	}
	if(maxchild!=heapsize){
		for(i=maxchild;i>1;i/=2){
			if(heapb[i/2]<lastelem)
				heapb[i]=heapb[i/2];
			else break;
		}
		heapb[i]=lastelem;		
	}
	--heapsize;
	return ret;
}

int main()
{
	int m,p;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%d%d",&prb[i].a,&prb[i].b);
		qsort(prb,n,sizeof(problem),comp);
		heapsize=0;
		int point=0;
		while(m){
			for(;point<n&&prb[point].a<=p;++point)
				insertheap(prb[point].b);
			int ret = deleteheap();
			if(ret!=-1){
				p+=ret;
				--m;
			}
			else break;
		}
		printf("%d\n",p);
	}
	return 0;
}
