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
		else if(p>11&&p<=100)
			ans=700;
		else if(p==101)
			ans=2700;
		else if(p>101&&p<=1000)
			ans=7000;
		else if(p==1001)
			ans=26999;
		else if(p==1002)
			ans=26999;
		else if(p>1002&&p<=10000)
			ans=70000;
		else if(p==10001)
			ans=270000;
		else if(p>10001&&p<=100000)
			ans=700000;
		else if(p==100001)
			ans=1699999;
		else if(p>100001&&p<=1000000)
			ans=7000000;
		else if(p==1000001)
			ans=27000000;
		else if(p>1000001&&p<=10000000)
			ans=70000000;
		else if(p==10000001)
			ans=270000000;
		else if(p>10000001&&p<=100000000)
			ans=700000000;
		printf("%d\n",ans);
	}
	return 0;
}
