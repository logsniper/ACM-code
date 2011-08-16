#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define MAX (1<<30)
#define MAXN 100
int w,h,n;

struct Point{
	int x,y;
	bool operator< (const Point &b)const{
		if(y!=b.y)	return y>b.y;
		else	return x<b.x;
	}
}tree[MAXN+4];

int px,py,plen;

int calUP(){
	plen = 0;
	for(int tid=0;tid<n+4;++tid){//确定矩形下底
		if(tid>0 && tree[tid].y==tree[tid-1].y)	continue;
		for(int i=0;i<=tid;++i){//确定矩形左边 
//			printf("(%d,%d): ",tree[i].x,tree[tid].y);
			int min = MAX;
			for(int j=0;j<=tid;++j){//遍历搜索矩形右和上边 
				if(tree[j].x<=tree[i].x || tree[j].y<=tree[tid].y)	continue;
				int tw = tree[j].x - tree[i].x;
				int th = tree[j].y-tree[tid].y;
				if(tw>h-tree[tid].y)	tw = h-tree[tid].y;
				if(th>w-tree[i].x)	th = w-tree[i].x;
				if(tw>=th && min>tw)	min=tw;
				else if(tw<th && min>th)	min=th;
			}
//			printf("%d\n",min);
			if(min < MAX && plen < min){
				plen = min;
				px = tree[i].x;
				py = tree[tid].y;
			}
		}
	}

}

int main(){
//	freopen("in.txt","r",stdin);
	string str1,str2;
	while(cin>>n>>w>>h){
		for(int i=0;i<n;++i)	cin>>tree[i].x>>tree[i].y;
		tree[n].x=0,tree[n].y=h;
		tree[n+1].x=w,tree[n+1].y=h;
		tree[n+2].x=0,tree[n+2].y=0;
		tree[n+3].x=w,tree[n+3].y=0;
		sort(tree,tree+n+4);
//		for(int i=0;i<n+4;++i)	cout<<tree[i].x<<" "<<tree[i].y<<endl;
		calUP();
		printf("%d %d %d\n",px,py,plen);
	}
	return 0;
}
