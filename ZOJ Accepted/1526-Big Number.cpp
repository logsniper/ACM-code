#include<iostream>
//#include<time.h>
using namespace std;
double fuck;
int shit[8000001];

int main()
{
	int N;
	int p,max,min,k;
	double tmp,hd;
	int i,ans;
//	double start,finish,duration;   //记录开始时间和结束时间
	fuck=3.77682;shit[0]=11733475;
//	start=clock();

	cin>>N;
	max=2000000;min=2000000;
	while(N--){
		cin>>p;
		if(p>max){
			for(k=max+1;k<=p;k++){
				tmp=fuck*k;
				shit[k-min]=shit[k-1-min];
				for(i=0;tmp>=10;i++){
					tmp/=10;
					shit[k-min]++;
				}
				fuck=tmp;
			}
			max=p;
			cout<<shit[p-min]<<endl;
		}
		else if(p>min)	cout<<shit[p-min]<<endl;
		else {
			hd=1;ans=1;
			for(k=1;k<=p;k++){
				tmp=hd*k;
				for(i=0;tmp>=10;i++){
					tmp/=10;
					ans++;
				}
				hd=tmp;
			}
			cout<<ans<<endl;
		}
	}
//	finish=clock();
//	duration=(double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<duration<<endl;
	return 0;
}
