#include <cstdio>
#include <cstdlib>
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
bool dfs(bool state[],int len[],int num,int now,int side,int tgt,int sideid)
{
	bool flag;
	state[now]=true;
//	printf("%d %d %d\n",side,now,len[now]);
	side+=len[now];
	if(sideid==3&&side==tgt)	return true;
	else if(side==tgt){
		int i;
		for(i=0;i<num&&state[i];++i);
		flag=dfs(state,len,num,i,0,tgt,sideid+1);
// 		printf("%d : ",side);
// 		for(int i=0;i<num;++i)
// 			printf("%d ",state[i]);
// 		printf("\n");
		if(flag)	return true;
	}
	else if(side<tgt){
		for(int i=now+1;i<num&&side+len[i]<=tgt;++i){
			if(!state[i]){
				flag=dfs(state,len,num,i,side,tgt,sideid);
				if(flag)	return true;
			}
		}
	}
	state[now]=false;
	return false;
}

int main()
{
//	freopen("input.txt","r",stdin);
	bool state[20];
	int len[20];
	int N,M;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&M);
		int sum=0;
		for(int i=0;i<M;++i){
			scanf("%d",&len[i]);
			sum+=len[i];
			state[i]=false;
		}
		qsort(len,M,sizeof(int),comp);
// 		for(int i=0;i<M;++i)
// 			printf("%d ",len[i]);
// 		printf("\n");
		if(sum%4!=0){
			printf("no\n");
			continue;
		}
		else{
			bool key=dfs(state,len,M,0,0,sum/4,1);
			if(key)	printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}