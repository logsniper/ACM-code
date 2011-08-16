#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct NODE{
	int id,track;
	bool operator < (const NODE &b)const
	{
		return id<b.id;
	}
	bool operator == (const NODE &b)const
	{
		return id==b.id;
	}
};
NODE node[200000];
int track;
set<NODE> tk;
int main()
{
	int n,m;
	int k;
	while(scanf("%d%d",&n,&m)&&(n>0||m>0)){
		tk.clear();
		track=0;
		bool able=true;;
		for(int i=0;i<n;++i){
			scanf("%d",&k);
			if(!able)	continue;
			node[i].id=k;

			set<NODE>::iterator it = tk.find(node[i]);
			if(it!=tk.end()){
				node[i].track=it->track;
				continue;
			}

			it = tk.lower_bound(node[i]);

			if(it==tk.begin()&&track<m){
				node[i].track = ++track;
				tk.insert(node[i]);
			}
			else if(it==tk.begin()){
				able=false;
			}
			else{
				--it;
				node[i].track=it->track;
				tk.erase(it);
				tk.insert(node[i]);
			}

		}
		if(!able){
			printf("Transportation failed\n");
			continue;
		}
		for(int i=0;i<n;++i){
			if(i>0)	putchar(' ');
			printf("%d",node[i].track);
		}
		putchar('\n');
		sort(node,node+n);
		for(int i=0;i<n;++i){
			if(i>0)	putchar(' ');
			printf("%d",node[i].track);
		}
		putchar('\n');
	}
	return 0;
}