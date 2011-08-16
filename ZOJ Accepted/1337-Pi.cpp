#include<cstdio>
#include<math.h>
using namespace std;

int judge(int a,int b)
{
	for(int k=2;k<=a&&k<=b;k++)
		if(a%k==0&&b%k==0) return 0;
	return 1;
}

int main()
{
	int N;
	int p[50],k=0;
	double Pi;
	while(scanf("%d",&N)&&N!=0){
		int all=N*(N-1)/2,right=0;
		for(int i=0;i<N;i++)
			 scanf("%d",&p[i]);
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++){
				if(judge(p[i],p[j]))
					right++;
			}		
		if(right==0) printf("No estimate for this data set.\n");
		else {
			Pi=sqrt(6.0*(double)all/(double)right);
			printf("%.6f\n",Pi);
		}
	}
}
