#include<cstdio>
#include<map>
using namespace std;
int main()
{
	map<int ,int> res;
	int n;
	while(scanf("%d",&n)!=EOF){
		int i=0;
		int key;
		res.clear();
		for(i=0;i<n;++i){
			scanf("%d",&key);
			if(res[key])	++res[key];
			else
				res[key]=1;
		}
		map<int,int>::iterator mp;
		for(mp = res.begin();mp!=res.end();++mp)
			if(mp->second > n/2){
				key = mp->first;
				break;
			}
		printf("%d\n",key);
	}
	return 0;
}
