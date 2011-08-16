#include<cstdio>
using namespace std;
int main()
{
	int T,N;
	char item[12];
	int score[2008];
	int i,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%s",item);
		scanf("%d",&N);
		for(i=0;i<N;i++)	scanf("%d",score+i);
		ans=score[0];
		if(item[0]=='F')
			for(i=1;i<N;i++){
				if(ans>score[i])	ans=score[i];
			}
		else //if(item[0]=='H'||item[0]=='S')
			for(i=1;i<N;i++){
				if(ans<score[i])	ans=score[i];
			}
		printf("%d\n",ans);
	}
	return 0;
}
