#include<cstdio>
using namespace std;

int main()
{
	int k,N;
	char ch[71];
	scanf("%d%*c",&N);
	while(N--){
		k=0;
		do{
			scanf("%c",&ch[k]);
		}while(ch[k++]!='\n');
		k--;
		for(int i=k-1;i>=0;i--)
			printf("%c",ch[i]);
		printf("\n");
	}
	return 0;
}
