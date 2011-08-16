#include<cstdio>
#include<cstring>
int main()
{
	int N,K,i,j;
	char memory[100][24];
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%s",memory[i]);
	scanf("%d",&K);
	while(K--){
		int n,ans=0;
		char word[24];
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%s",word);
			for(i=0;i<N;i++)
				if(strcmp(word,memory[i])==0){
					ans++;break;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
