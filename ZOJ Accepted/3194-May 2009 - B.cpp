#include<cstdio>
#include<cstdlib>
using namespace std;
int comp(const void*a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int main()
{
	int t,n;
	int x[1000],y[1000],step[1000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)	scanf("%d%d",&x[i],&y[i]);
		qsort(x,n,sizeof(int),comp);
		qsort(y,n,sizeof(int),comp);
		for(i=0;i<n;i++){
			if(i==0)
				step[i]=x[i]-x[i+1];
			else if(i==n-1)
				step[i]=x[i-1]-x[i];
			else
				step[i]=x[i-1]-x[i+1];
		}
		qsort(step,n,sizeof(int),comp);
		double area=0.0;
		for(i=0;i<n;i++)
			area+=(double)step[i]*y[i]/2;

		printf("%.1lf\n",area);
	}
	return 0;
}
