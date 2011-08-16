#include<iostream>
using namespace std;
int main()
{
	int n;
	int ring,now;
	int i,j;
	int left;
	bool used[101];
	while(cin>>n&&n!=0){
		left=-1;
		now=n;
		for(i=1;i<=n;i++)
			used[i]=0;
		for(i=0;i<n;i++){
			cin>>ring;
			if(left>=0){
				left++;
				continue;
			}
			if(used[ring]==0){
				for(j=now;j>=ring;j--)
					used[j]=1;
				now=ring;
			}
			else{
				now=now-1;
				used[now]=1;
			}
			if(now==0)	left=0;
		}
		left++;
		cout<<left<<endl;
	}
	return 0;
}
