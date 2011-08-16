#include<cstdio>
#include<cstdlib>
long long num[30];
long long ans[30];
int m,found;

int comp(const void *a, const void *b)
{
	return *(long long *)a-*(long long*)b;
}

bool bsearch(long long tgt,int start,int end)
{
	if(start>end)	return false;
	int mid=(start+end)/2;
	if(num[mid]==tgt)	return true;
	if(num[mid]<tgt)	return bsearch(tgt,mid+1,end);
	if(num[mid]>tgt)	return bsearch(tgt,start,mid-1);
}

void dfs(int total_len,int now_len,int now_pos,long long now_sum)
{
	if(now_len==total_len){
		if(bsearch(now_sum,now_pos,m-1)){
			for(int i=0;i<now_len;++i){
				if(i)	printf("+%lld",ans[i]);
				else printf("%lld",ans[i]);
			}
			printf("=%lld\n",now_sum);
			++found;
		}
		return;
	}
	if(now_pos>=m||now_sum+num[now_pos]>num[m-1])	return ;
	ans[now_len]=num[now_pos];
	dfs(total_len,now_len+1,now_pos+1,now_sum+num[now_pos]);
	dfs(total_len,now_len,now_pos+1,now_sum);
	return ;
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&m);
		for(int i=0;i<m;++i)
			scanf("%lld",&num[i]);
		if(m<=2){
			printf("Can't find any equations.\n\n");
			continue;
		}
		qsort(num,m,sizeof(long long),comp);
		found=0;
		int len,maxlen=0;
		for(long long tmp=0;tmp<=num[m-1]&&maxlen<m;++maxlen)
			tmp+=num[maxlen];
		for(len=2;len<maxlen;++len)
			dfs(len,0,0,0);
		if(found==0)
			printf("Can't find any equations.\n");
		printf("\n");
	}
	return 0;
}
