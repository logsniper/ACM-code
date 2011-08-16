#include<cstdio>
//#include<ctime>
using namespace std;
int sum[500001];
int main()
{
	int N,i,j,k;
//	long start=clock();
	for(i=1;i<=500000;i++)
		sum[i]=0;
	for(j=1;j<=250000;j++)
		for(i=j+j;i<=500000;i+=j)
			sum[i]+=j;
//	long finish=clock();
//	double cost=double(finish-start)/CLOCKS_PER_SEC;
//	cout<<cost<<"s"<<endl;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&k);
		printf("%d\n",sum[k]);	
	}
	return 0;
}
