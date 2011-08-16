#include<iostream>
using namespace std;
long long table[501][501];
long long find(int sum,int last)
{
	if(sum<last)	return 0;
	if(sum==1||sum==2||sum==last)	return 1;
	long long ans=0;
	int i=1;
	int last_min;
	while(ans<sum-last){
		ans+=i;
		i++;
	}
	ans-=--i;
	last_min=(sum-last-ans)>i?(sum-last-ans):i;
	for(ans=0,i=last_min;i<last;i++){
		if(table[sum-last][i]==-1)	table[sum-last][i]=find(sum-last,i);
		ans+=table[sum-last][i];
	}
	return ans;
}
int main()
{
	int N;
	long long ans;
	int i,j;
	int last_min;
	for(i=0;i<501;i++)
		for(j=0;j<501;j++)
			table[i][j]=-1;
	while(cin>>N&&N!=0){
		ans=0,i=1;
		while(ans<N){
			ans+=i;
			i++;
		}
		ans-=--i;
		last_min=(N-ans)>i?(N-ans):i;
		for(ans=0,i=last_min;i<N;i++){
			if(table[N][i]==-1)	table[N][i]=find(N,i);
			ans+=table[N][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
