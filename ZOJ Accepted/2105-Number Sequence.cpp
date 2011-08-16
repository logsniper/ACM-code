#include<cstdio>
using namespace std;

int main()
{
	int A,B;
	long n;
	int x,y,k,tmp;
	int result;
	while(scanf("%d%d%ld",&A,&B,&n)!=EOF&&(A!=0||B!=0||n!=0)){
		A=A%7;
		B=B%7;
		if(n>=3&&B!=0){
			x=1;
			y=A+B;
			k=1;
			while(x!=1||y!=1){
				tmp=y;
				y=(A*y+B*x)%7;
				x=tmp;
				k++;
			}
			n=n%k;
			if(n==0) n=k;
		}
		else if(n>=3&&B==0){
			k=6;
			n=n%k;
			if(n==0) n=k;
		}
		
		if(n<3) result =1;
		else{
			x=1;
			y=1;
			for(int i=3;i<=n;i++){
				tmp=y;
				y=(A*y+B*x)%7;
				x=tmp;
			}
			result = y;
		}
		printf("%d\n",result);
	}
	return 0;
}
