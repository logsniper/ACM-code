#include<cstdio>
#include<string>
using namespace std;
string week(int n)
{
	switch(n%7){
		case 0 : return "Saturday";
		case 1 : return "Sunday";
		case 2 : return "Monday";
		case 3 : return "Tuesday";
		case 4 : return "Wednesday";
		case 5 : return "Thursday";
		case 6 : return "Friday";
	}
}
inline bool is365(int year)
{
	if(year%400==0)
		return false;
	if(year%100&&year%4==0)
		return false;
	return true;
}
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int n;
	int year,mth,day;
	while(scanf("%d",&n)&&n>=0){
		year=2000,mth=1,day=1;
		string wk;
		for(int i=0;i<10;++i)
			wk[i]='\0';
		wk = week(n);
		++n;
		while(1){
			int yd;
			if(is365(year))	yd=365;
			else	yd=366;
			if(n<=yd)	break;
			n-=yd;
			++year;
		}
		if(is365(year))	month[2]=28;
		else month[2]=29;
		for(mth=1;mth<=12;++mth){
			if(n<=month[mth]){
				day=n;
				break;
			}
			n-=month[mth];
		}
		char pri[100];
		if(mth<10&&day<10)
			sprintf(pri,"%d-0%d-0%d %s",year,mth,day,wk.data());
		else if(mth>=10&&day<10)
			sprintf(pri,"%d-%d-0%d %s",year,mth,day,wk.data());
		else if(mth<10&&day>=10)
			sprintf(pri,"%d-0%d-%d %s",year,mth,day,wk.data());
		else
			sprintf(pri,"%d-%d-%d %s",year,mth,day,wk.data());
		printf("%s\n",pri);
	}
	return 0;
}
