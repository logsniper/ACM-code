#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct{
	int left,right;
}PAGE;
int comp(const void *a,const void *b)
{
	int key=((PAGE*)a)->left-((PAGE*)b)->left;
	if(key==0)
		key=((PAGE*)b)->right-((PAGE*)a)->right;
	return key;
}
int main()
{
	int T,n;
	PAGE page[5000];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&page[i].left,&page[i].right);
		qsort(page,n,sizeof(PAGE),comp);
		int last=0,k=0,ans=0;
		while(last<n){
//			printf(" !%d!  ",last);
			int tmp=k;
			while(page[tmp].left<=last+1){
				if(page[tmp].right>page[k].right)
					k=tmp;
				tmp++;
			}
			last=page[k].right;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
