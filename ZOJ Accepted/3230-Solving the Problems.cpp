#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef struct {
	int a,b;
}problem;

problem prb[100001];
bool solved[100001];
int n;

int comp(const void *x,const void *y)
{
	int ret=((problem*)y)->b-((problem*)x)->b;
	if(!ret)
		ret=((problem*)x)->a-((problem*)y)->a;
	return ret;
}

int main()
{
	int m;
	int p;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF){
		int maxa=0;
		for(int i=0;i<n;++i){
			scanf("%d%d",&prb[i].a,&prb[i].b);
			if(maxa<prb[i].a)	maxa=prb[i].a;
		}
		qsort(prb,n,sizeof(problem),comp);
		memset(solved,false,n);
		for(int i=0;i<n;++i){
			if(prb[i].a<=p&&!solved[i]){
				solved[i]=true;
				p+=prb[i].b;
				i=-1;
				--m;
//				if(m==0)	break;
				if(m==0||p>=maxa)	break;
			}
		}
		if(p>=maxa&&m){
			for(int i=0;i<n;++i){
				if(!solved[i]){
					solved[i]=true;
					p+=prb[i].b;
					--m;if(m==0)	break;
				}
			}
		}
		printf("%d\n",p);
	}
	return 0;
}
