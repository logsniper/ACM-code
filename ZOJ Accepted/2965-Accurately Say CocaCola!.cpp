#include<cstdio>
int main()
{
	int T,p;
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&p);
		if(p==1)
			ans=7;
		else if(p==2)
			ans=27;
		else if(p>=3&&p<=10)
			ans=70;
		else if(p==11)
			ans=270;
		else if(p>=10&&p<=99)
			ans=700;
		printf("%d\n",ans);
	}
	return 0;
}
