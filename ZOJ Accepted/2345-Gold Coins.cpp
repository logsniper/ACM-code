#include<cstdio>
using namespace std;
int main()
{
	int N;
	int day[21],day_tmp;
	int total[21];
	int n,i,j;
	scanf("%d",&N);
	while(N--){
		for(i=0;scanf("%d",day+i)&&day[i]!=0;i++){
			total[i]=0;
			day_tmp=day[i];
			for(j=1;day_tmp>j;j++){
				total[i]+=j*j;
				day_tmp-=j;
			}
			total[i]+=day_tmp*j;
		}
		n=i;
		for(i=0;i<n;i++)
			printf("%d %d\n",day[i],total[i]);
		if(N>=1)	printf("\n");
	}
	return 0;
} 
