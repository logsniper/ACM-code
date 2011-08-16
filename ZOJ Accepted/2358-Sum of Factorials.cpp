#include<cstdio>
#include<cstdlib>
int rslt[1040],num;
int fact[10];

int comp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

void dfs(int nownum,int nowrslt){
	if(nownum==9){
		rslt[num++]=nowrslt;
		rslt[num++]=nowrslt+fact[9];
	}
	else{
		dfs(nownum+1,nowrslt);
		dfs(nownum+1,nowrslt+fact[nownum]);
	}
	return; 
}

void init()
{
	num=0;
	fact[0]=1;
	for(int i=1;i<10;i++)
		fact[i]=fact[i-1]*i;
	dfs(0,0);
	qsort(rslt,num,sizeof(int),comp);
	return ;
}

bool bsearch(const int tgt,int s,int e)
{
	if(s>e)	return false;
	int mid=(s+e)/2;
	if(rslt[mid]==tgt)	return true;
	else if(rslt[mid]>tgt)
		return bsearch(tgt,s,mid-1);
	else
		return bsearch(tgt,mid+1,e);
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF&&n>=0){
		if(n!=0&&bsearch(n,0,num-1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
