#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef struct CITY{
	double x,y;
}CITY;

typedef struct Min{
	int number;
	double length;
}Min;
double prim(CITY city[],int n)
{
	Min min;
	double shortest_path=0;
	double short_way[100];
	int closest[100];
	double c[100][100];
	bool s[100];
	int i,j,s_num;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++){
			c[i][j]=sqrt((city[i].x-city[j].x)*(city[i].x-city[j].x)+(city[i].y-city[j].y)*(city[i].y-city[j].y));
			c[j][i]=c[i][j];
		}
	s[0]=true;
	for(i=1;i<n;i++){
		closest[i]=0;
		short_way[i]=c[i][0];
		s[i]=false;
	}
	s_num=1;
	while(s_num<n){
		min.length=30000;
		for(i=1;i<n;i++)
			if(min.length>short_way[i]&&s[i]==false){
				min.length=short_way[i];
				min.number=i;
			}
		s[min.number]=true;
		s_num++;
		shortest_path+=min.length;
		for(i=1;i<n;i++)
			if(s[i]==false&&c[i][min.number]<short_way[i]){
				short_way[i]=c[i][min.number];
				closest[i]=min.number;
			}
	}
	return shortest_path;
}

int main()
{
	int n,i,CS=0;
	double ans;
	CITY city[100];
	int NewLine=0;
	while(cin>>n&&n!=0){
		if(CS++)	printf("\n");	
		for(i=0;i<n;i++)	cin>>city[i].x>>city[i].y;

		ans=prim(city,n);
		printf("Case #%d:\n",CS);
		printf("The minimal distance is: %.2lf\n",ans);
	}
	return 0;
}
