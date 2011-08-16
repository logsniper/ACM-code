#include<cstdio>
using namespace std;
bool related[11][11];
double cost[11];
bool state[11];
void change(double *score,bool state[],int n,int chnum)
{
	int i;
	for(i=1;i<=n;i++)
		if(related[chnum][i]==1)
			state[i]=!state[i];
	(*score)*=(double)(1-cost[chnum]);
}
bool result(int n)
{
	int i;
	for(i=1;i<=n;i++)
		if(state[i]==1)	return 0;
	return 1;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		int i,j,k,tmp;
		//input
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				related[i][j]=0;
			related[i][i]=1;
			scanf("%d",&k);
			for(j=0;j<k;j++){
				scanf("%d",&tmp);
				related[i][tmp]=1;
			}
			scanf("%lf",&cost[i]);
			cost[i]=double(cost[i])/100;
		}
		//running
		int now;
		int TotalTimes=1;
		double MaxScore=0;
		bool finished=0;
		for(i=1;i<=n;i++)
			TotalTimes*=2;
		for(now=1;now<TotalTimes;now++){
			for(i=1;i<=n;i++)
				state[i]=1;
			int time_tmp=now;
			double NowScore=m;
			for(i=1;i<=n;i++){
				if(time_tmp%2)
					change(&NowScore,state,n,i);
				time_tmp/=2;
			}
			if(result(n)&&NowScore>=MaxScore){
				MaxScore=NowScore;
				finished=1;
			}
		}
		if(finished)
			printf("%.2lf\n",MaxScore);
		else printf("-1\n");
	}
	return 0;
}
