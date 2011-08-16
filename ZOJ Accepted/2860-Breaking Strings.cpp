#include<cstdio>
int leastcost[1002][1002];
int lstcst_k[1002][1002];
int breakpos[1002];
void dp(int a,int b)
{
	int step,start,breakpoint;
	for(start=a;start<=b;start++){
		leastcost[start][start]=0;
		lstcst_k[start][start]=start;
	}
	for(start=a;start<=b-1;start++){
		leastcost[start][start+1]=0;
		lstcst_k[start][start+1]=start;
	}
	for(start=a;start<=b-2;start++){
		leastcost[start][start+2]=breakpos[start+2]-breakpos[start];
		lstcst_k[start][start+2]=start+1;
	}
	for(step=3;step<=b-a;step++)
		for(start=a;start<=b-step;start++){
			int min=2000000000,k,end=start+step;
			int dist=breakpos[end]-breakpos[start];
			for(breakpoint=lstcst_k[start][end-1];breakpoint<=lstcst_k[start+1][end];breakpoint++){
				int tmp=leastcost[start][breakpoint]+leastcost[breakpoint][end];
				if(tmp<min){
					min=tmp;
					k=breakpoint;
				}
			}
			leastcost[start][end]=min+dist;
			lstcst_k[start][end]=k;
//			printf("%d %d %d\n",lstcst_k[start][start+step-1],k,lstcst_k[start+1][start+step]);
		}
}
int main()
{
	int N,M;
//	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&N,&M)!=EOF){
		int i;
		breakpos[0]=0;
		for(i=0;i<M;i++){
			scanf("%d",&breakpos[i+1]);
		}
		breakpos[M+1]=N;
		dp(0,M+1);
		int ans=leastcost[0][M+1];
		printf("%d\n",ans);
	}
	return 0;
}
