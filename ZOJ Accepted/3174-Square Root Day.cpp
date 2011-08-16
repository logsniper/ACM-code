#include<cstdio>
#include<cmath>
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		int year,num=0;;
		for(year=x;year<=y;year++){
			int year1=year%100;
			int month1=(int)sqrt((double)year1);
			if(year1==month1*month1&&month1>=1)	num++;
			int year2=year%1000;
			int month2=(int)sqrt((double)year2);
			if(year2==month2*month2&&month2>=1&&month2<=12&&year1!=year2)	num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
