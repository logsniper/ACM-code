#include<cstdlib>
#include<cstdio>

struct STICK{
	int length,weight;
	bool handled;
};

int comp(const void *a,const void *b)
{
	int ans = ((STICK*)a)->weight - ((STICK*)b)->weight;
	if(ans == 0)
		ans = ((STICK*)a)->length - ((STICK*)b)->length;
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T,n,i,j,left,setup;
	struct STICK stick[5000]; 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&stick[i].length,&stick[i].weight);
			stick[i].handled=false;
		}
		qsort(stick,n,sizeof(STICK),comp);
		left=n,setup=0,i=0;
		int prel,prew;
		while(left){
			if(i==0){
				++setup;
				prel=0,prew=0;
			}
			if(stick[i].handled==false&&stick[i].length>=prel&&stick[i].weight>=prew){
				prel=stick[i].length;
				prew=stick[i].weight;
				stick[i].handled=true;
				left--;
			}
			i=(i+1)%n;
		}
		printf("%d\n",setup);
	}
	return 0;
}
