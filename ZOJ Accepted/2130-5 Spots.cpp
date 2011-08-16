#include<cstdio>
using namespace std;
char matrix[60][64];
char matrix0[60][64];
int H,M,h,m;
int match(int x,int y)
{
	int xi,yi;
	for(yi=0;yi<h;yi++)
		for(xi=0;xi<m;xi++){
			if(matrix0[yi][xi]=='.')	continue;
			if(matrix0[yi][xi]!=matrix[yi+y][xi+x])
				return 0;
		}
	return 1;
}
int main()
{
	while(scanf("%d%d%d%d",&H,&M,&h,&m)!=EOF){
		int xi,yi,ans=0;
		for(yi=0;yi<H;yi++)
			scanf("%s",matrix[yi]);
		for(yi=0;yi<h;yi++)
			scanf("%s",matrix0[yi]);
		for(yi=0;yi<H-h+1;yi++)
			for(xi=0;xi<M-m+1;xi++)
				ans+=match(xi,yi);
		printf("%d\n",ans);
	}
	return 0;
}
