#include<cstdio>
#include<cstdlib>
#define dist 4500
using namespace std;
typedef struct{
	double v;
	int t;
	double sec_cost;
}STUDENT;
int comp(const void *a,const void *b)
{
	double key=(double)((STUDENT*)a)->t-((STUDENT*)b)->t;
	if(key==0)	key=((STUDENT*)b)->v-((STUDENT*)a)->v;
	return int(key);
}
int main()
{
	STUDENT stu[10000];
	int N;
	while(scanf("%d",&N)&&N!=0){
		int i;
		double min=4500;
		for(i=0;i<N;i++){
			scanf("%lf%d",&stu[i].v,&stu[i].t);
			if(stu[i].t<0){
				N--;
				i--;
				continue;
			}
			stu[i].sec_cost=(double)stu[i].t+dist*3.6/stu[i].v;
			if(stu[i].sec_cost<min)
				min=stu[i].sec_cost;
		}
		int tmp=int(min);
		if(min-tmp>0)	min++;
		printf("%.0lf\n",min);
	}
	return 0;
}
