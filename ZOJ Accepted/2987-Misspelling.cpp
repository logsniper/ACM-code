#include<cstdio>
#include<string.h>
using namespace std;
int main(){
	int N,n,M,length,i;
	char word[80];
	scanf("%d",&N);
	for(n=1;n<=N;n++){
		scanf("%d%s",&M,word);
		length=strlen(word);
		printf("%d ",n);
		for(i=0;i<length;i++){
			if(i!=M-1) printf("%c",word[i]);
		}
		printf("\n");
	}
	return 0;
}
