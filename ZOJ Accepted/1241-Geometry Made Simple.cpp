#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main()
{
	float a,b,c;
	int k=1;
	while(1){
		cin>>a>>b>>c;
		if(c==-1) {
			c=sqrt(a*a+b*b);
			printf("Triangle #%d\nc = %.3f\n",k++,c);
		}
		else if(a==-1&&c*c-b*b>0) {
			a=sqrt(c*c-b*b);
			printf("Triangle #%d\na = %.3f\n",k++,a);
		}
		else if(b==-1&&c*c-a*a>0) {
			b=sqrt(c*c-a*a);
			printf("Triangle #%d\nb = %.3f\n",k++,b);
		}
		else if(a*a+b*b+c*c==0) break;
		else printf("Triangle #%d\nImpossible.\n",k++);
		printf("\n");
	}
}
