#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int w,d,x,N=0;
	double y,tmp;
	while(cin>>w>>d&&(w!=0&&d!=0)){
		N++;
		tmp=(double)810*w/d;
		y=(double)(5730*log(tmp)/log(2));
//		cout<<"Sample #"<<N<<endl;
//		cout<<"The approximate age is "<<log(tmp)<<"years.\n";
		x=(int)y;
		if(x<10000){
			if(x%100<=50&&x%100>0){
				x=x/100;
				x=x*100;
			}
			else if(x%100!=0){
				x=x/100;
				x=(x+1)*100;
			}			
		}
		else if(x>10000){
			if(x%1000<=500&&x%1000>0){
				x=x/1000;
				x=x*1000;
			}
			else if(x%1000!=0){
				x=x/1000;
				x=(x+1)*1000;
			}		
		}
		cout<<"Sample #"<<N<<endl;
		cout<<"The approximate age is "<<x<<" years.\n\n";
	}
	return 0;
}
