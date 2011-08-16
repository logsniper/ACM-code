#include<iostream>
using namespace std;
#define MAX 50
bool tree[MAX][MAX];
typedef struct NODE{
	int from;
	int child_num;
}NODE;
int main()
{
	NODE node[MAX];
	int a,b,i,j;
	int node_number,root_num;
	int T=0;
	bool IsTree;
	while(1){
		T++;
		IsTree=1;
		root_num=0;
		node_number=0;
		for(i=0;i<MAX;i++){
			node[i].from=0;
			node[i].child_num=0;
			for(j=0;j<MAX;j++)
				tree[i][j]=false;
		}
		cin>>a>>b;
		if(a==-1&&b==-1)	break;
		do{
			if(a==0&&b==0)	break;
			if(node_number<a)	node_number=a;
			if(node_number<b)	node_number=b;
			if(node[b].from==0)
				node[b].from=a;
			else{
				IsTree=0;
			}
			node[a].child_num++;
			if(tree[a][b]==true)	IsTree=0;
			tree[a][b]=true;tree[b][a]=true;
			for(i=0;i<MAX;i++){
				if(tree[i][b]==true){
					tree[i][a]=true;tree[a][i]=true;
				}
				if(tree[a][i]==true){
					tree[i][b]=true;tree[b][i]=true;
				}
			}
		}while(cin>>a>>b);
		for(i=1;i<=node_number&&IsTree;i++){
			if(node[i].from==0){
				if(node[i].child_num>0)
					root_num++;
			}
		}
		if(root_num!=1)	IsTree=0;
		if(node_number==0)	IsTree=1;
		if(IsTree)	cout<<"Case "<<T<<" is a tree.\n";
		else cout<<"Case "<<T<<" is not a tree.\n";
	}
	return 0;
}
