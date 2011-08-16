#include<cstdio>

class Node{
public:
	int l,r;
	int max;
	Node *lc,*rc;
public:
	void initNode(int ll, int rr){
		l = ll;
		r = rr;
		max = 0;
		lc = NULL;
		rc = NULL;
	}
};

const int MAXN = 50010;
Node tree[MAXN*3];

class Tree{
private:
	Node* createTree(int index, int a,int b){
		Node* head = &tree[index];
		head->initNode(a, b);
		if(a < b){
			int mid = (a+b)/2;
			head->lc = createTree(index*2,a,mid);
			head->rc = createTree(index*2+1,mid+1,b);
		}
		return head;
	}
	int search(Node* p,int a,int b){
		int max = 0;
		if(a < p->l)	a = p->l;
		if(b > p->r) b = p->r;
		if(p->l==a && p->r==b){
			max = p->max;
		}
		else{
			int mid = (p->l+p->r)/2;
			if(a<=mid && b>mid){
				int ret1 = search(p->lc,a,mid);
				if(max < ret1)	max = ret1;
				int ret2 = search(p->rc,mid+1,b);
				if(max < ret2)	max = ret2;
			}
			else if(b <= mid){
				int ret = search(p->lc,a,b);
				if(max < ret)	max = ret;
			}
			else if(a > mid){
				int ret = search(p->rc,a,b);
				if(max < ret)	max = ret;
			}
		}
		return max;
	}
public:
	Tree(int n){
		createTree(1,0,n-1);
	}
	void updateNode(int n, int value){
		Node* p = &tree[1];
		while(p != NULL){
			if(p->max < value)	p->max = value;
			if(n <= (p->l+p->r)/2)	p = p->lc;
			else	p = p->rc;
		}
	}
	int getMax(int a,int b){
		return search(&tree[1], a,b);
	}
};

int si[MAXN],xi[MAXN],yi[MAXN];

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i=0;i<n;++i){
			scanf("%d%d%d",&si[i],&xi[i],&yi[i]);
		}
		Tree dp(n);
		for(int i=n-1;i>=0;--i){
			int l = i + xi[i];
			int r = i + yi[i]-1;
			int max = 0;
			if(l<n){
				if(r >= n){
					r = n-1;
				}
				max = dp.getMax(l, r);
			}
			dp.updateNode(i, max + si[i]);
		}
		printf("%d\n",dp.getMax(0,0));
	}
	return 0;
}
