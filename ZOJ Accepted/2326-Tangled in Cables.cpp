#include<cstdio>
#include<string>
#include<map>
#include<queue>
using namespace std;
int group[1000];
map <string,int> mp;
typedef class WAY{
public:
	int from,to;
	float value;
	bool operator < (const WAY &it) const{
		return value > it.value;
	}
}WAY;
int main()
{
	float cable,cost;
	int n,m;
	char from[24],to[24];
	WAY tmp;
	while(scanf("%f",&cable)!=EOF){
		mp.clear();
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",from);
			mp[string(from)]=i;
		}
		for(int i=0;i<n;++i)
				group[i]=0;
		priority_queue<WAY> way;
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%s%s%f",from,to,&tmp.value);
			tmp.from = mp[string(from)],tmp.to = mp[string(to)];
			way.push(tmp);
		}

		int waynum=n-1,gcount=1;
		cost = 0.0f;
		while(waynum&&!way.empty()){
			WAY nowtop = way.top();
 			if(group[nowtop.from]>0&&group[nowtop.to]>0&&group[nowtop.from]!=group[nowtop.to]){
				if(group[nowtop.from]<group[nowtop.to]){
					int gnum = group[nowtop.to];
					for(int i=0;i<n;++i)
						if(group[i]==gnum)
							group[i]=group[nowtop.from];
				}
				else if(group[nowtop.to]<group[nowtop.from]){
					int gnum = group[nowtop.from];
					for(int i=0;i<n;++i)
						if(group[i]==gnum)
							group[i]=group[nowtop.to];
				}
				cost+=nowtop.value;
				--waynum;
			}
			else if(group[nowtop.from]>0&&group[nowtop.to]==0){
				group[nowtop.to]=group[nowtop.from];
				cost+=nowtop.value;
				--waynum;
			}
			else if(group[nowtop.to]>0&&group[nowtop.from]==0){
				group[nowtop.from]=group[nowtop.to];
				cost+=nowtop.value;
				--waynum;
			}
			else if(group[nowtop.from]==0&&group[nowtop.to]==0){
				group[nowtop.from]=gcount;
				group[nowtop.to]=gcount;
				++gcount;
				cost+=nowtop.value;
				--waynum;
			}
			way.pop();
		}
		if(cost<=cable)
			printf("Need %.1f miles of cable\n",cost);
		else
			printf("Not enough cable\n");

// 		for(int i=0;i<n;++i){
// 			printf("%d ",group[i]);
// 		}
// 		printf("\n");
	}
	return 0;
}
