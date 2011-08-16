#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct{
	int J,F;
	double ratio;
}ROOM;
int comp(const void *a,const void *b)
{
	double key=(double)((ROOM*)b)->ratio-((ROOM*)a)->ratio;
	if(key>0)	return 1;
	if(key<0)	return -1;
	key=((ROOM*)b)->F-((ROOM*)a)->F;
	return (int)key;
}
int main()
{
	ROOM room[1000];
	int M,N;
	while(scanf("%d%d",&M,&N)&&!(N==-1&&M==-1)){
		int i,left=M;
		for(i=0;i<N;i++){
			scanf("%d%d",&room[i].J,&room[i].F);
			if(room[i].F==0){
				room[i].ratio=1001;
				continue;
			}
			room[i].ratio=double(room[i].J)/room[i].F;
		}
		qsort(room,N,sizeof(ROOM),comp);
//		for(i=0;i<N;i++)
//			printf("%d %d %lf\n",room[i].J,room[i].F,room[i].ratio);
		double ans=0;
		for(i=0;room[i].F<=left&&i<N;i++){
			left-=room[i].F;
			ans+=room[i].J;
		}
		if(i<N)
			ans+=double(room[i].J*left)/room[i].F;
		printf("%.3lf\n",ans);
	}
	return 0;
}
