#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define MAXN 1210
using namespace std;
struct Line{
	int x1,y1;
	int x2,y2;
	int value;
	void swap()
	{
		if(x1>x2||y1>y2){
			int t=x1;x1=x2;x2=t;
			t=y1;y1=y2;y2=t;
		}
	}
};
Line line[MAXN];

set<int> st;
map<int ,int> mp;
void LSH(int n)
{
	st.clear(),mp.clear();
	int count;

	for(int i=0;i<n;++i){
		if(st.find(line[i].x1)==st.end())	st.insert(line[i].x1);
		if(st.find(line[i].x2)==st.end())	st.insert(line[i].x2);
	}
	count=0;
	for(set<int>::iterator it=st.begin();it!=st.end();++it){
		mp[*it]=++count;
	}
	for(int i=0;i<n;++i)
		line[i].x1=mp[line[i].x1],line[i].x2=mp[line[i].x2];
	st.clear(),mp.clear();

	for(int i=0;i<n;++i){
		if(st.find(line[i].y1)==st.end())	st.insert(line[i].y1);
		if(st.find(line[i].y2)==st.end())	st.insert(line[i].y2);
	}
	count=0;
	for(set<int>::iterator it=st.begin();it!=st.end();++it){
		mp[*it]=++count;
	}
	for(int i=0;i<n;++i)
		line[i].y1=mp[line[i].y1],line[i].y2=mp[line[i].y2];
	st.clear(),mp.clear();
}

int father[MAXN*MAXN];
int find(int t)
{
	int k=t;
	while(k!=father[k])	k=father[k];
	while(father[t]!=k){
		int r=father[t];
		father[t]=k;
		t=r;
	}
	return k;
}
void Union(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(fa!=fb) father[fb]=fa;
}
struct Edge{
	int s,e,val;
	bool operator <(const Edge &b)const
	{
		return val>b.val;
	}
};
bool mm[4][MAXN][MAXN];
priority_queue<Edge> ed;
long long Kruskal(int n)
{
	while(!ed.empty())	ed.pop();
	memset(mm,0,4*MAXN*MAXN);
	Edge ted;
	int maxwidth=0,maxheight=0;
	for(int i=0;i<n;++i){
		if(line[i].x1>maxwidth)		maxwidth=line[i].x1;
		if(line[i].x2>maxwidth)		maxwidth=line[i].x2;
		if(line[i].y1>maxheight)		maxheight=line[i].y1;
		if(line[i].y2>maxheight)		maxheight=line[i].y2;
	}
	maxheight++,maxwidth++;

	int totalsize=(maxwidth)*(maxheight);
	for(int i=0;i<=totalsize;++i)
		father[i]=i;

	for(int i=0;i<n;++i){
		line[i].swap();
		if(line[i].x1==line[i].x2){
			for(int j=line[i].y1;j<line[i].y2;++j){
				mm[1][ j ][ line[i].x1-1 ]=true;
				mm[3][ j ][ line[i].x1 ]=true;
				ted.s=line[i].x1-1+j*maxwidth;
				ted.e=line[i].x1+j*maxwidth;
				ted.val = line[i].value;
				ed.push(ted);
			}
		}
		else if(line[i].y1==line[i].y2){
			for(int j=line[i].x1;j<line[i].x2;++j){
				mm[0][ line[i].y1 ][ j ]=true;
				mm[2][ line[i].y1-1 ][ j ]=true;
				ted.s=(line[i].y1-1)*maxwidth+j;
				ted.e=line[i].y1*maxwidth+j;
				ted.val=line[i].value;
				ed.push(ted);
			}
		}
	}

	for(int i=0;i<maxheight;++i){
		for(int j=0;j<maxwidth;++j){
			if(i>0&&!mm[0][i][j])		Union((i-1)*maxwidth+j,i*maxwidth+j);
			if(j+1<maxwidth&&!mm[1][i][j])	Union(i*maxwidth+j,i*maxwidth+j+1);
			if(i+1<maxheight&&!mm[2][i][j])	Union(i*maxwidth+j,(i+1)*maxwidth+j);
			if(j>0&&!mm[3][i][j])		Union(i*maxwidth+j-1,i*maxwidth+j);
		}
	}

// 	for(int i=0;i<maxheight;++i){
// 		for(int j=0;j<maxwidth;++j){
// 			printf("%4d(%2d)",i*maxwidth+j,find(i*maxwidth+j));
// 		}
// 		printf("\n");
// 	}
	long long res=0;
	while(!ed.empty()){
		ted=ed.top();
		ed.pop();
		if(find(ted.s)==find(ted.e)){
			continue;
		}
//		printf("%d %d %d\n",ted.s,ted.e,ted.val);
		res+=ted.val;
		Union(ted.s, ted.e);
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2,&line[i].value);
		LSH(n);
// 		for(int i=0;i<n;++i)
// 			printf("%d %d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].value);
		long long res=Kruskal(n);
		printf("%lld\n",res);
	}
	return 0;
}