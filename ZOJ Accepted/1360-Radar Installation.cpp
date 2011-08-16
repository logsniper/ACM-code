#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef struct Island{
	int x;
	int y;
}Island;
int comp(const void* a,const void* b)
{
	int ans1;
	ans1=((Island *)a)->x-((Island *)b)->x;
	if(ans1!=0)	return ans1;
	else return ((Island *)b)->y-((Island *)a)->y;
}
int main()
{
	int n,d;
	Island island[1000];
	int i,j,k;
	int inradar,radar,ans;
	double x_radar;
	int first[1000],last[1000];
	bool finished,flag;
	int test=0;
	bool true_radar[1000];
	while(cin>>n>>d&&(n!=0||d!=0)){
		test++;
		for(i=0;i<n;i++)
			cin>>island[i].x>>island[i].y;
		qsort(island,n,sizeof(Island),comp);
		radar=0;
		inradar=0;
		finished=1;
		first[radar]=0;
		last[radar]=0;
		while(inradar<n){
			if(island[inradar].y>d){
				finished=0;
				break;
			}
			x_radar=double(island[inradar].x+sqrt(d*d-(island[inradar].y)*(island[inradar].y)));
			radar++;
			true_radar[radar]=true;
			first[radar]=inradar;

			for(j=1;j<radar;j++){
				if(true_radar[j]==false)	continue;			
				flag=1;
				for(i=first[j];i<=last[j];i++){
					if(double((island[i].x-x_radar)*(island[i].x-x_radar)+(island[i].y)*(island[i].y))<=d*d)	continue;
					flag=0;break;
				}
				if(radar!=0&&flag)	true_radar[j]=false;
			}

			inradar++;
			while(inradar<n&&double((island[inradar].x-x_radar)*(island[inradar].x-x_radar)+(island[inradar].y)*(island[inradar].y))<=d*d){
				inradar++;
			}
			last[radar]=inradar-1;
		}
		for(i=1,ans=0;i<=radar;i++){
//			cout<<true_radar[i]<<" ";
			if(true_radar[i]==true)	ans++;
		}
		cout<<"Case "<<test<<": ";
		if(finished)
			cout<<ans<<endl;
		else
			cout<<"-1\n";
	}
	return 0;
}
