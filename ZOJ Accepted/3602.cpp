#include <map>
#include <cstdio>
#include <cmath>
#include <deque>
#include <cstring>
using namespace std;

const int PRIME = 200003;
const int MAXN = 100004;

int hash( int a) 
{ 
   a = (a+0x7ed55d16) + (a<<12); 
   a = (a^0xc761c23c) ^ (a>>19); 
   a = (a+0x165667b1) + (a<<5); 
   a = (a+0xd3a2646c) ^ (a<<9); 
   a = (a+0xfd7046c5) + (a<<3); // <<和 +的组合是可逆的 
   a = (a^0xb55a4f09) ^ (a>>16);  
   return a; 
}

int hash(pair<int,int> pii){
	int MASK = (1<<16) -1;
	int h1 = hash(pii.first);
	int h2 = hash(pii.second);
	int ret = ((((h1>>16)^(h2&MASK))<<16) + ((h1&MASK)^(h2>>16))) % PRIME;
	return ret>=0?ret:(ret+PRIME);
}

int left[2][MAXN],right[2][MAXN];
int buffer[MAXN];
int finished[MAXN];
int count_tree[2][PRIME];
map<pair<int,int>, int > p2i;
map<int, pair<int,int> > i2p;

int post_order_visit(int id){
	memset(finished,0,sizeof finished);
	memset(count_tree[id],0,sizeof count_tree[id]);
	deque<int> stack;
	stack.push_back(1);
	int ret;
	int* hcode = &buffer[1];
	hcode[0] = 0;
	hcode[-1] = -1;
	while(! stack.empty()){
		int now = stack.back();
		if(finished[now] == 2){
			pair<int,int> v(hcode[left[id][now]],hcode[right[id][now]]);
			map<pair<int,int>, int>::iterator it = p2i.find(v);
			int h;
			if(it != p2i.end()){
				h = it->second;
			} else {
				h = hash(v);
				map<int,pair<int,int> >::iterator it2 = i2p.find(h);
				while(it2 != i2p.end() and it2->second != v){
					++ h;
					h = h>PRIME?1:h;
					it2 = i2p.find(h);
				}
				p2i[v] = h;
				i2p[h] = v;
			}
//			printf("pov: %d\t%d\t%d\n",id,now,h);
			++ count_tree[id][h];
			hcode[now] = h;
			stack.pop_back();
		}
		else if(finished[now] == 0){
			if(left[id][now] != -1){
				stack.push_back(left[id][now]);
			}
			finished[now] = 1;
		}
		else if(finished[now] == 1){
			if(right[id][now] != -1){
				stack.push_back(right[id][now]);
			}
			finished[now] = 2;
		}
	}
}

bool isprime(int N){
	if(N<=1) return false;
	else if(N<=3) return true;
	else{
		int k = sqrt(N);
		for(int i=2;i<=k;++i){
			if(N%i==0)	return false;
		}
	}
	return true;
}

int find_prime_larger_than(int N){
	while(! isprime(N)) ++ N;
	return N;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		p2i.clear();
		i2p.clear();
		pair<int,int> zero(0,0);
		p2i[zero] = 0;
		i2p[0] = zero;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%d%d",&left[0][i],&right[0][i]);
		}
		for(int i=1;i<=m;++i){
			scanf("%d%d",&left[1][i],&right[1][i]);
		}
		post_order_visit(0);
		post_order_visit(1);
/*		for(int i=1;i<=n;++i){
			printf("%d\t%d\t%d\n",i,finished[i],buffer[i+1]);
		}
		for(int i=1;i<=m;++i){
			printf("%d\t%d\t%d\n",i,finished[i],buffer[i+1]);
		}
*/
		long long res = 0;
		for(int i=0;i<PRIME;++i){
			if(count_tree[0][i]>0 && count_tree[1][i]>0){
				res += (long long)count_tree[0][i] * count_tree[1][i];
			}
		}
		printf("%lld\n",res);
	}
}
