#include<cstdio>
#include<cstdlib>
typedef struct whitenode{
	int s,e;
}whitenode;
int comp(const void *a,const void *b)
{
	int ret = ((whitenode*)a)->s - ((whitenode*)b)->s;
	if(ret==0)
		ret = ((whitenode*)b)->e - ((whitenode*)a)->e;
	return ret;
}
whitenode seg[1000000];
int numseg;
void cal(int n)
{
	char color[2];
	int start,end;
	numseg=0;
	while(n--){
		scanf("%d%d%s",&start,&end,color);
		if(start>end){
			int tmp=start;
			start=end;
			end=tmp;
		}
		if(color[0]=='w'){
			seg[numseg].s=start;
			seg[numseg].e=end;
			++numseg;
		}
		else{
			for(int i=0;i<numseg;++i){
				if(start<seg[i].s){
					if(end>=seg[i].s){
						if(end<seg[i].e)
							seg[i].s=end+1;
						else{
							seg[i].s=0,seg[i].e=-10;
						}
					}
				}
				else if(start<=seg[i].e){
					if(end<=seg[i].e){
						seg[numseg].s=end+1,seg[numseg].e=seg[i].e;
						seg[i].e=start-1;
						++numseg;
					}
					else
						seg[i].e=start-1;
				}
			}
		}
	}
	qsort(seg,numseg,sizeof(whitenode),comp);
	int flag=0;
	for(int i=1;i<numseg;++i){
		if(seg[i].s<=seg[flag].e+1){
			if(seg[i].e>seg[flag].e)
				seg[flag].e=seg[i].e;
		}
		else flag=i;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int N;
	while(scanf("%d",&N)!=EOF){
		cal(N);
		int maxstep=0,key=-1;
		for(int i=0;i<numseg;++i){
			if(seg[i].e-seg[i].s+1>maxstep){
				key=i,maxstep=seg[i].e-seg[i].s+1;
			}
		}
		if(key==-1)
			printf("Oh, my god\n");
		else
			printf("%d %d\n",seg[key].s,seg[key].e);
	}
	return 0;
}
