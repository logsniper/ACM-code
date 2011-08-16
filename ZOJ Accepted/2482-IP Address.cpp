#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int N,i,j;
	int a[4];
	char bi[33];
	int num[4][8];
	scanf("%d",&N);
	while(N--){
		scanf("%s",bi);
		for(i=0;i<32;i++)
			num[i/8][i%8]=bi[i]-'0';
		for(i=0;i<4;i++){
			a[i]=0;
			for(j=7;j>=0;j--){
				if(num[i][j]==1)	a[i]+=(int)pow(2,7-j);
			}
		}
		printf("%d.%d.%d.%d\n",a[0],a[1],a[2],a[3]);
	}
	return 0;
}
