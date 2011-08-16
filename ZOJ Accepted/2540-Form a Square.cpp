#include<cstdio>
using namespace std;
int x[4],y[4];
bool DYZJ(int a,int b,int c)
{
	int point[3];
	if((x[b]-x[a])*(x[c]-x[a])+(y[b]-y[a])*(y[c]-y[a])==0)
		point[0]=a,point[1]=b,point[2]=c;
	else if((x[a]-x[b])*(x[c]-x[b])+(y[a]-y[b])*(y[c]-y[b])==0)
		point[0]=b,point[1]=a,point[2]=c;
	else if((x[a]-x[c])*(x[b]-x[c])+(y[a]-y[c])*(y[b]-y[c])==0)
		point[0]=c,point[1]=a,point[2]=b;
	else return 0;
	int edge1=(x[point[1]]-x[point[0]])*(x[point[1]]-x[point[0]])+(y[point[1]]-y[point[0]])*(y[point[1]]-y[point[0]]);
	int edge2=(x[point[2]]-x[point[0]])*(x[point[2]]-x[point[0]])+(y[point[2]]-y[point[0]])*(y[point[2]]-y[point[0]]);
	if(edge1==edge2)	return 1;
	else return 0;
}
int main()
{
	int N,n=0;
	scanf("%d",&N);
	while(n<N){
		n++;
		int i;
		for(i=0;i<4;i++)
			scanf("%d%d",&x[i],&y[i]);
		printf("Case %d:\n",n);
		if(DYZJ(1,2,3)&&DYZJ(0,2,3)&&DYZJ(1,0,3))
			printf("Yes\n");
		else printf("No\n");
		if(n<N)	printf("\n");
	}
	return 0;
}
