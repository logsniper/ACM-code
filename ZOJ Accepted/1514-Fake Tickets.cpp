#include<iostream>
using namespace std;
int main()
{
	int n,m,now,i,ans;
	bool exist[20002],checked[20002];
	while(cin>>n>>m&&(n!=0||m!=0)){
		ans=0;
		for(i=1;i<=n;i++){
			exist[i]=0;
			checked[i]=0;
		}
		for(i=0;i<m;i++){
			cin>>now;
			if(exist[now]&&checked[now]==0){
				ans++;
				checked[now]=1;
			}
			else if(exist[now]==0)
				exist[now]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
