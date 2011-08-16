#include<cstdio>
using namespace std;
int P[50],I[50],N;
void PtoI()
{
	int i,j,inver_number;
	for(i=0;i<N;i++){
		inver_number=0;
		for(j=0;P[j]!=P[i];j++){
			if(P[j]>P[i])	inver_number++;
		}
		I[P[i]-1]=inver_number;
	}
}
void ItoP()
{
	int i,j,k;
	int flag[50];
	for(i=0;i<N;i++)	flag[i]=0;
	for(i=0;i<N;i++){
		k=0;
		for(j=0;k<I[i];j++)
			if(flag[j]==0)	k++;
		while(flag[j]!=0)	j++;
		flag[j]=1;
		P[j]=i+1;
	}
}
int main()
{
	int i;
	char x;
	while(scanf("%d",&N)&&N!=0){
		getchar();
		scanf("%c",&x);
		if(x=='P')	{
			for(i=0;i<N;i++)	scanf("%d",P+i);
			PtoI();
			for(i=0;i<N;i++){
				printf("%d",I[i]);
				if(i!=N-1)	printf(" ");
			}
		}
		else if(x=='I')	{
			for(i=0;i<N;i++)	scanf("%d",I+i);
			ItoP();
			for(i=0;i<N;i++){
				printf("%d",P[i]);
				if(i!=N-1)	printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
