#include<iostream>
using namespace std;
int main()
{
	int N,i;
	bool light[10000],test1[10000],test2[10000];
	int ans1,ans2;
	for(i=0;i<10000;i++){
		if(i%2){
			test1[i]=1;test2[i]=0;
		}
		else{
			test1[i]=0;test2[i]=1;
		}
	}
	while(cin>>N){
		ans1=0;ans2=0;
		for(i=0;i<N;i++){
			cin>>light[i];
			if(light[i]!=test1[i])	ans1++;
			if(light[i]!=test2[i])	ans2++;
		}
		cout<<(ans1<ans2?ans1:ans2)<<endl;
	}
	return 0;
}
