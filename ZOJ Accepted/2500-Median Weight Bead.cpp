#include<cstdio>
typedef struct Bead{
	int smallerNum,biggerNum;
	int smaller[100],bigger[100];
}Bead;
Bead bead[100];
bool visit[100];
int n;

void dfsFindSmaller(int k)
{
	for(int i=0;i<bead[k].smallerNum;++i)
		if(!visit[bead[k].smaller[i]]){
			visit[bead[k].smaller[i]]=true;
			dfsFindSmaller(bead[k].smaller[i]);
		}
}

void dfsFindBigger(int k)
{
	for(int i=0;i<bead[k].biggerNum;++i)
		if(!visit[bead[k].bigger[i]]){
			visit[bead[k].bigger[i]]=true;
			dfsFindBigger(bead[k].bigger[i]);
		}
}

inline int findSmaller(int k)
{
	for(int i=0;i<n;++i)
		visit[i]=false;
	dfsFindSmaller(k);
	int ret=0;
	for(int i=0;i<n;++i)
		if(visit[i])	++ret;
//	printf("%d : %d\n",k,ret);
	return ret;
}

inline int findBigger(int k)
{
	for(int i=0;i<n;++i)
		visit[i]=false;
	dfsFindBigger(k);
	int ret=0;
	for(int i=0;i<n;++i)
		if(visit[i])	++ret;
//	printf("%d\n",ret);
	return ret;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int t,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			bead[i].smallerNum=0;
			bead[i].biggerNum=0;
		}
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			--a,--b;
			bead[a].smaller[bead[a].smallerNum++]=b;
			bead[b].bigger[bead[b].biggerNum++]=a;
		}
		
		int count=0,rate=(n-1)/2;
		for(int i=0;i<n;++i)
			if(findBigger(i)>rate||findSmaller(i)>rate)
				++count;
		printf("%d\n",count);
	}
	return 0;
}
