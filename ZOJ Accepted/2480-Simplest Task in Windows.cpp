#include<cstdio>
using namespace std;
typedef struct{
	int x1,y1;
	int x2,y2;
}WINDOW;
int main()
{
	int N,M;
	WINDOW window[10];
	while(scanf("%d",&N)&&N!=0){
		int i,j;
		for(i=0;i<N;i++)
			scanf("%d%d%d%d",&window[i].x1,&window[i].y1,&window[i].x2,&window[i].y2);
		scanf("%d",&M);
		for(j=0;j<M;j++){
			int x,y,ans=-1;
			scanf("%d%d",&x,&y);
			for(i=0;i<N;i++)
				if(x>=window[i].x1&&x<=window[i].x2&&y>=window[i].y1&&y<=window[i].y2)
					ans=i;
			printf("%d\n",ans);
		}
	}
	return 0;
}
