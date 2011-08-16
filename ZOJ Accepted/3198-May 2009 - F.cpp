#include<cstdio>
int main()
{
	int T,s1,s2,array[100000],now1,now2,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&s1);
		for(now1=0;now1<s1;now1++)			
			scanf("%d",&array[now1]);
		now1=0,ans=0;
		scanf("%d",&s2);
		for(now2=0;now2<s2;now2++){
			int tmp;
			scanf("%d",&tmp);
			while(tmp>array[now1])
				now1++;
			if(tmp==array[now1]){
				ans++;
				now1++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
