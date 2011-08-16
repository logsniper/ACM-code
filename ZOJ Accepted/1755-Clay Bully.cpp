#include<cstdio>
using namespace std;
int main()
{
	int block[9][4];
	char name[9][10];
	int n,i;
	while(scanf("%d",&n)&&n!=-1){
		int avg=0;
		for(i=0;i<n;i++){
			scanf("%d %d %d %s",block[i]+1,block[i]+2,block[i]+3,name[i]);
			block[i][0]=block[i][1]*block[i][2]*block[i][3];
			avg+=block[i][0];
		}
		avg/=n;
		int max,min;
		for(i=0;i<n;i++){
			if(block[i][0]>avg)	max=i;
			else if(block[i][0]<avg)	min=i;
		}
		printf("%s took clay from %s.\n",name[max],name[min]);
	}
	return 0;
}
