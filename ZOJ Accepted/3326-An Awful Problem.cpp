#include <cstdio>
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int dayperyear = 52;

bool thatyear(int y)
{
	return ((y%4==0)&&(y%100!=0))||(y%400==0);
}

bool isprime(int n)
{
	if(n==1)	return false;
	if(n==2||n==3||n==5)	return true;
	if(n%2==0)	return false;
	if(n%3==0)	return false;
	if(n%5==0)	return false;
	return true;
}

int afterTheDays(int y,int m,int d)
{
	int lastyear=0;
	if(thatyear(y))	month[2]=29;
	else		month[2]=28;
	for(int i=m;i<=12;++i){
		if(!isprime(i))	continue;
		int j=1;
		if(i==m)	j=d;
		for(;j<=month[i];++j)
			if(isprime(j))		{
				++lastyear;
			}
	}
	return lastyear;
}
int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	int y[2],m[2],d[2];
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<2;++i){
			scanf("%d%d%d",&y[i],&m[i],&d[i]);
			if(y[i]>2999)	y[i]=2999;
			if(y[i]<1000)	y[i]=1000;
		}
		int res=0;
		for(int i=y[0]+1;i<y[1];++i){
			if(thatyear(i))	res+=(dayperyear+1);
			else		res+=dayperyear;
		}
//		printf("%d\n",res);
		int firstyear=afterTheDays(y[0],m[0],d[0]);
		int lastyear=afterTheDays(y[1],m[1],d[1]);
//		printf("%d %d\n",firstyear,lastyear);
		if(y[0]==y[1]){	
			if(isprime(m[1])&&isprime(d[1])) 	lastyear--;
			printf("%d\n",firstyear-lastyear);
		}
		else{
			lastyear = dayperyear-lastyear;
			if(thatyear(y[1]))	lastyear++;
			if(isprime(m[1])&&isprime(d[1]))		lastyear++;
			printf("%d\n",res+lastyear+firstyear);
		}
	}
	return 0;
}