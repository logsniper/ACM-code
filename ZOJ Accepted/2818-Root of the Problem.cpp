#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int A,a1,a2,B,N;
	while(scanf("%d%d",&B,&N)&&(B!=0||N!=0)){
		for(A=1,a2=1;a2<=B;A++){a1=a2;a2=(int)pow(A,N);}
		A--;
		if(B-a1<=a2-B)	A--;
		printf("%d\n",A);
	}
	return 0;
}
