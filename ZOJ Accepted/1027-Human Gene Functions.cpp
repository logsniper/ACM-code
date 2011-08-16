#include<cstdio>
#define MAX(A,B) (A>B?A:B)

char costtable0[6]={'A','C','G','T','-'};
int costtable[5][5]={{5,-1,-2,-1,-3},
					{-1,5,-3,-2,-4},
					{-2,-3,5,-2,-2},
					{-1,-2,-2,5,-1},
					{-3,-4,-2,-1,-1000000}};

int cost(char a,char b)
{
	int ai,bi,i;
	for(i=0;i<5;i++){
		if(a==costtable0[i])	ai=i;
		if(b==costtable0[i])	bi=i;
	}
	return costtable[ai][bi];
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T,al,bl;
	char a[104],b[104];
	int x[104],y[104];
	scanf("%d",&T);
	while(T--){
		int i,j;
		scanf("%d%s%d%s",&al,a,&bl,b);
		for(i=al;i>0;i--)
			a[i]=a[i-1];
		for(i=bl;i>0;i--)
			b[i]=b[i-1];
		x[0]=0;
		for(i=1;i<=al;i++)
			x[i]=x[i-1]+cost(a[i],'-');
		for(j=1;j<=bl;j++){
			y[0]=x[0]+cost(b[j],'-');
			for(i=1;i<=al;i++){
				int t1=x[i-1]+cost(a[i],b[j]);
				int t2=x[i]+cost(b[j],'-');
				int t3=y[i-1]+cost(a[i],'-');
				y[i]=MAX(t1,MAX(t2,t3));
			}
			for(i=0;i<=al;i++)
				x[i]=y[i];
		}
		int ans=x[al];
		printf("%d\n",ans);
	}
	return 0;
}
