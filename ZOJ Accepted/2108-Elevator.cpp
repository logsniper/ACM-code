#include<cstdio>
using namespace std;
int main()
{
	int N;
	int floor[1000];
	int way;
	while(scanf("%d",&N)&&N!=0){
		floor[0]=0;
		way=0;
		for(int i=1;i<=N;i++){
			scanf("%d",floor+i);
			if(floor[i]>floor[i-1])
				way+=6*(floor[i]-floor[i-1])+5;
			else if(floor[i]<floor[i-1])
				way+=4*(floor[i-1]-floor[i])+5;
			else
				way+=5;
		}
		printf("%d\n",way);
	}
	return 0;
}
