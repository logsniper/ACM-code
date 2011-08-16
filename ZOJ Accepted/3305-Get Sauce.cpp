#include <cstdio>
#include <algorithm>
using namespace std;
bool used[17];
class bottle{
public:
	int matnum;
	int mat[16];
	bool operator<(const bottle &b) const
	{
		if(matnum<b.matnum)	return true;
		else	return false;
	}
	inline bool check()
	{
		for(int i=0;i<matnum;++i)
			if(used[mat[i]])	return false;
		return true;
	}
	inline void Set()
	{
		for(int i=0;i<matnum;++i)	used[mat[i]]=true;
	}
	inline void reset()
	{
		for(int i=0;i<matnum;++i)	used[mat[i]]=false;
	}
};
bottle bot[50000];
int botnum;
int maxdpeth;

void dfs(int kth,int matleft,int depth)
{
// 	for(int i=1;i<=16;++i)	printf("%d",used[i]);
// 	printf("\n");
	if(depth>maxdpeth)	maxdpeth=depth;
	if(kth>=botnum||matleft<bot[kth].matnum){
		return ;
	}
	for(int i=kth;i<botnum&&bot[i].matnum<=matleft&&(maxdpeth-depth)*bot[i].matnum<=matleft;++i){
		if(bot[i].check()){
			bot[i].Set();
			dfs(i+1,matleft-bot[i].matnum,depth+1);
			bot[i].reset();
		}
	}
}

int main()
{
	int n;
	while(scanf("%d%d",&n,&botnum)!=EOF){
		for(int i=0;i<botnum;++i){
			scanf("%d",&(bot[i].matnum));
			for(int j=0;j<bot[i].matnum;++j)
				scanf("%d",&(bot[i].mat[j]));
		}
		sort(bot,bot+botnum);
		for(int i=1;i<=16;++i)	used[i]=false;
		maxdpeth=0;
		dfs(0,n,0);
		printf("%d\n",maxdpeth);
	}
	return 0;
}