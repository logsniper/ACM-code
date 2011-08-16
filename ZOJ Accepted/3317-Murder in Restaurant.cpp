#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct murder{
	int t1,t2;
	int id;
	int roomforhim;
	bool operator <(const murder &b)const{	return t1<b.t1;	}
};
bool comp(const murder &a,const murder &b)
{
	return a.id<b.id;
}
murder md[120];
int room[120];
bool lived[120];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		for(int i=0;i<n;++i){
			scanf("%d%d",&md[i].t1,&md[i].t2);
			md[i].id=i;
		}
		sort(md,md+n);
		memset(room,0,m+1);
		memset(lived,0,m+1);
		for(int i=0;i<n;++i){
			bool exist=false;
			for(int j=1;j<=m;++j){
				if(!lived[j]||lived[j]&&md[room[j]].t2<=md[i].t1){
					exist=true;
					lived[j]=true;
					room[j]=i;
					md[i].roomforhim=j;
					break;
				}
			}
			if(!exist)	md[i].roomforhim=0;
		}
		sort(md,md+n,comp);
		for(int i=0;i<n;++i)
			printf("%d\n",md[i].roomforhim);
	}
	return 0;
}