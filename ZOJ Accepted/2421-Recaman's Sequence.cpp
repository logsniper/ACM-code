#include<cstdio>
using namespace std;
int main()
{
	bool in[3100000];
	int recaman[500001],i;
	recaman[0]=0,in[0]=1;
	for(i=1;i<1000000;i++){
		in[i]=0;
	}
	int max=0;
	for(i=1;i<500001;i++){
		int tmp=recaman[i-1]-i;
		if(tmp<=0||in[tmp]==1)
			tmp=recaman[i-1]+i;
		recaman[i]=tmp;
		in[tmp]=1;
		if(tmp>max)	max=tmp;
	}
//	printf("%d\n",max);
	int k;
	while(scanf("%d",&k)&&k>=0){
		printf("%d\n",recaman[k]);
	}
	return 0;
}
