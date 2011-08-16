#include<cstdio>
using namespace std;
int main()
{
	int n,m,c,time=0;
	int cap[21];
	bool state[21];
	while(scanf("%d%d%d",&n,&m,&c)&&!(n==0&&m==0&&c==0)){
		time++;
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",&cap[i]);
			state[i]=0;
		}
		int MaxBlow=0,NowBlow=0;
		bool fused=0;
		for(i=0;i<m;i++){
			int operate;
			scanf("%d",&operate);
			if(state[operate]==0){
				NowBlow+=cap[operate];
				state[operate]=1;
			}
			else{
				NowBlow-=cap[operate];
				state[operate]=0;
			}
			if(NowBlow>MaxBlow)	MaxBlow=NowBlow;
			if(NowBlow>c)	fused=1;
		}
		if(fused)
			printf("Sequence %d\nFuse was blown.\n\n",time);
		else
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",time,MaxBlow);
	}
	return 0;
}
