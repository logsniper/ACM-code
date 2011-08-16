#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char start[12],end[12];
	int R,C;
	char image1[9][10],image2[8][8];
	while(scanf("%s",start)!=EOF){
		if(strcmp(start,"ENDOFINPUT")==0)	break;
		scanf("%d%d",&R,&C);
		int ri,ci;
		for(ri=0;ri<R;ri++)
			scanf("%s",image1[ri]);
		scanf("%s",end);
		for(ri=0;ri<R-1;ri++){
			for(ci=0;ci<C-1;ci++){
				image2[ri][ci]= (image1[ri][ci]+image1[ri+1][ci]+
								image1[ri][ci+1]+image1[ri+1][ci+1])/4-'0';
				printf("%d",image2[ri][ci]);
			}
			printf("\n");
		}
	}
	return 0;
}
