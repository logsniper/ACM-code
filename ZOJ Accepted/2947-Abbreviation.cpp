#include<cstdio>
using namespace std;
int main()
{
	int T,N,M;
	int i,j;
	char A,B,a[6],b[6];
	scanf("%d",&T);
	while(T--){
		i=j=0;
		scanf("%d",&N);
		getchar();
		while(scanf("%c",&A)&&A!='\n'){
			if(A>='A'&&A<='Z')	a[i++]=A;
		}
		scanf("%d",&M);
		getchar();
		while(scanf("%c",&B)&&B!='\n'){
			if(B>='A'&&B<='Z')	b[j++]=B;
		}
		if(N!=M)	printf("DIFFERENT\n");
		else {
			int flag=1;
			for(i=0;i<N;i++){
				if(a[i]!=b[i]){flag=0;break;}
			}
			if(flag)	printf("SAME\n");
			else	printf("DIFFERENT\n");
		}
	}
	return 0;
}
