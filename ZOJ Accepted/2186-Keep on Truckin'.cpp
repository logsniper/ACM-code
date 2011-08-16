#include<cstdio>
using namespace std;
void output(int high[])
{
	int i;
	for(i=0;i<3;i++)
		if(high[i]<=168){
			printf("CRASH %d\n",high[i]);
			return;
		}
	printf("NO CRASH\n");
	return ;
}
int main()
{
	int high[3];
	while(scanf("%d%d%d",high,high+1,high+2)!=EOF){
		output(high);
	}
	return 0;
}
