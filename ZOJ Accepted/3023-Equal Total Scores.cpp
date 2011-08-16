#include <cstdio>
#include <cstring>
int main()
{
	int n,m;
	bool Taro[102],Hanako[102];
	int sumT,sumH,tmp;
	while(scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
		sumT=sumH=0;
		memset(Taro,0,102);
		memset(Hanako,0,102);
		for(int i=0;i<n;++i){
			scanf("%d",&tmp);
			sumT+=tmp;
			Taro[tmp]=true;
		}
		for(int i=0;i<m;++i){
			scanf("%d",&tmp);
			sumH+=tmp;
			Hanako[tmp]=true;
		}
		int diff=sumT-sumH;
		if(diff%2){
			printf("-1\n");
			continue;
		}
		diff/=2;
		bool able=false;
		for(int i=0;i<=100;++i){
			if(Taro[i]&&i-diff>=0&&i-diff<=100&&Hanako[i-diff]){
				able=true;
				printf("%d %d\n",i,i-diff);
				break;
			}
		}
		if(!able)	printf("-1\n");
	}
	return 0;
}