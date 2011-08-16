#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	bool appear[100004];
	vector<int> list;
	int cash,N,n,d;
	while(scanf("%d%d",&cash,&N)!=EOF){
		memset(appear,0,sizeof(bool)*100004);
		list.clear();
		list.push_back(0);
		appear[0]=true;
		for(int i=0;i<N;++i){
			scanf("%d%d",&n,&d);
			int size=list.size();
			for(int j=0;j<size;++j){
				for(int k=1;k<=n;++k){
					int tmp=list[j]+k*d;
					if(tmp>100000)	break;
					else if(tmp<=100000&&!appear[tmp]){
						list.push_back(tmp);
						appear[tmp]=true;
					}
				}
			}
		}
		for(;cash>=0;--cash)
			if(appear[cash]){
				printf("%d\n",cash);
				break;
			}
	}
	return 0;
} 
