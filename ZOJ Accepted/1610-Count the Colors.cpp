#include<iostream>
using namespace std;
int main()
{
	int n,i,length;
	int color_max,j;
	int seg[8001],left,right,color_now,color[8001];
	while(cin>>n){
		color_max=0;
		length=0;
		for(i=0;i<8001;i++){
			seg[i]=-1;
			color[i]=0;
		}
		for(i=0;i<n;i++){
			cin>>left>>right>>color_now;
			if(right>length)	length=right;
			if(color_now>color_max)	color_max=color_now;
			for(j=left;j<right;j++)
				seg[j]=color_now;
		}
		for(i=0;i<length;i++){
			if((seg[i]!=seg[i-1]&&seg[i]!=-1)||i==0)
				color[seg[i]]++;
		}
		for(j=0;j<=color_max;j++){
			if(color[j]>0)
				cout<<j<<" "<<color[j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
