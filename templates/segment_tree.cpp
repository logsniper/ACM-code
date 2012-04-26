#include <cstdio>
#include <iostream>
#include <new>
using namespace std;

/*
 * segment tree for elems' updating and summing
 */
template<class T>
class segment_tree{
public:
	const int MAXSIZE ;

	segment_tree(bool debug = false, int maxsize = 200000):debugOn(debug),buffer(NULL),updates(NULL),MAXSIZE(maxsize){}

	int init(T *array, int sz, const T& _zero){
		buffer = new(nothrow) T[MAXSIZE*2];
		updates = new(nothrow) T[MAXSIZE*2];
		if(buffer == NULL || updates == NULL)	return 1;

		size = 1;
		while( size < sz){
			size <<= 1;
			if(size < 0 || size > MAXSIZE)	return 1;
		}
		zero = _zero;
		for(int i=0;i<sz;++i) buffer[size + i] = array[i];
		for(int i = size + sz;i<(size<<1); ++i) buffer[i] = zero;
		// BEGIN +++++++ modify for different segment tree below
		for(int i=size-1;i>0;--i)	buffer[i] = buffer[i*2] + buffer[i*2+1]; 
		// OVER  ------- modify for different segment tree above
		for(int i=0;i<size+size;++i)	updates[i] = zero;
		return 0;
	}

	~segment_tree(){
		delete buffer;
		delete updates;
	}

	void print(){
		for(int depth = 0;(1<<depth)<=size;++depth){
			int start = 1<<depth;
			int end = 1<<(depth+1);
			cout<<"["<<start<<","<<end<<") :\t";
			for(int i=start;i<end;++i){
				cout<<"("<<buffer[i]<<","<<updates[i]<<")\t";
			}
			cout<<endl;
		}
	}

	int query(int start,int end, T& out){
		if(start > end || end >= size)	return 1;
		return _query(start,end,1,out);
	}

	int add(int start, int end, T val){
		if(start > end || end >= size)	return 1;
		return _add(start,end,1,val);
	}

private:
	/*
	 * return calculated elements between start and end inclusive.
	 */
	int _query(int start,int end,int index, T& out){
		int depth = 0;
		while((1<<(depth+1)) <= index){
			++ depth;
		}
		int seglength = size/(1<<depth);
		int mystart = seglength * (index - (1<<depth));
		int myend = mystart + seglength - 1;
		int retvalue = 0;
		if(debugOn){
			snprintf(log,sizeof log -1,"index : %d, depth : %d, query(%d,%d), actual range (%d,%d)\n",index,depth,start,end,mystart,myend);
			cout << log;
		}
		if(start < mystart || end > myend){
			if(debugOn){
				snprintf(log,sizeof log -1,"[ERROR]\tindex : %d, depth : %d, query(%d,%d), actual range (%d,%d)\n",index,depth,start,end,mystart,myend);
				cout << log;
			}
			retvalue = 1;
		}
		else if(start == mystart && end == myend){
			// BEGIN +++++++ modify for different segment tree below
			out = buffer[index] + updates[index] ;
			// OVER  ------- modify for different segment tree above
			if(start == end){
				buffer[index] = out;
				updates[index] = zero;
			}
		}
		else{
			updates[index*2] += (updates[index]>>1);
			updates[index*2+1] += (updates[index]>>1);
			// BEGIN +++++++ modify for different segment tree below
			buffer[index] = buffer[index] + updates[index] ;
			// OVER  ------- modify for different segment tree above
			updates[index] = zero;

			if(end < mystart + (seglength>>1) ){
				retvalue = _query(start,end,2*index,out);
			}
			else if(start >= mystart + (seglength>>1) ){
				retvalue = _query(start,end,2*index+1,out);
			}
			else{
				T x,y;
				if(0 == _query(start,mystart+(seglength>>1)-1,2*index,x)
						&& 0 == _query(mystart+(seglength>>1),end,2*index+1,y)){
					// BEGIN +++++++ modify for different segment tree below
					out = x + y;
					// OVER  ------- modify for different segment tree above
				} else {
					retvalue = 1;
				}
			}
		}
		if(debugOn)	cout << "query [" << start << ", " << end << "] = " << out << endl;
		return retvalue;
	}

	int _add(int start, int end, int index, T val){
		int depth = 0;
		while((1<<(depth+1)) <= index){
			++ depth;
		}
		int seglength = size/(1<<depth);
		int mystart = seglength * (index - (1<<depth));
		int myend = mystart + seglength - 1;
		int retvalue = 0;
		if(start < mystart || end > myend){
			if(debugOn){
				snprintf(log,sizeof log - 1,"[ERROR]\tindex : %d, depth : %d, add(%d,%d), actual range (%d,%d)\n",index,depth,start,end,mystart,myend);
				cout << log;
			}
			retvalue = 1;
		}
		else if(start == mystart && end == myend){
			// BEGIN +++++++ modify for different segment tree below
			updates[index] += val * (end-start+1);
			// OVER  ------- modify for different segment tree above
		} else {
			// BEGIN +++++++ modify for different segment tree below
			buffer[index] += val * (end-start+1);
			// OVER  ------- modify for different segment tree above
			if(end < mystart + (seglength>>1) ){
				retvalue = _add(start,end,2*index,val);
			}
			else if(start >= mystart + (seglength>>1) ){
				retvalue = _add(start,end,2*index+1,val);
			}
			else{
				if(0 != _add(start,mystart+(seglength>>1)-1,2*index,val)
						|| 0 != _add(mystart+(seglength>>1),end,2*index+1,val)){
					retvalue = 1;
				}
			}
		}
		if(debugOn){
			T out;
			_query(start,end,index,out);
			cout << "query after add [" << start << ", " << end << "] = " << out << endl;
		}
		return retvalue;
	}

private:
	bool debugOn;
	T *buffer;
	T *updates;
	char log[4096];
	int size;
	T zero;
};

long long a[100004];

bool test(){
	static int array[100];
	segment_tree<int> st(0);
	segment_tree<int> *ptr = &st;
	for(int i=0;i<100;++i){
		array[i] = 1;
	}
	int ret = ptr->init(array,100,0);
	//ptr->print();

	int res;
	ret = ptr->query(1,15,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 15)	return false;

	ret = ptr->add(1,15,2);
	cout << "return value = " << ret << endl;

	ret = ptr->query(1,15,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 45)	return false;

	ret = ptr->query(10,20,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 23)	return false;

	ret = ptr->add(10,20,2);
	cout << "return value = " << ret << endl;

	ret = ptr->query(10,20,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 45)	return false;

	ret = ptr->add(17,17,20);
	cout << "return value = " << ret << endl;

	ret = ptr->query(10,20,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 65)	return false;

	ret = ptr->query(17,17,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 23)	return false;

	ret = ptr->add(1,99,1);
	cout << "return value = " << ret << endl;

	ret = ptr->query(0,99,res);
	cout << "return value = " << ret << ", result = " << res << endl;
	if(res != 271)	return false;

	// ptr -> print();
	return true;
}

int main(){
	//cout << segment_tree<int>::test() << endl;
	segment_tree<long long> st(0, 200000);
	int N,Q;
	scanf("%d%d\n",&N,&Q);
	for(int i=0;i<N;++i)	scanf("%lld",&a[i]);
	st.init(a,N,0);
	for(int i=0;i<Q;++i){
		char type[8];
		int x,y;
		long long z;
		scanf("%s",type);
		if(type[0] == 'Q'){
			scanf("%d%d",&x,&y);
			long long res = 0;
			st.query(x-1,y-1,res);
			printf("%lld\n",res);
		} else {
			scanf("%d%d%lld",&x,&y,&z);
			st.add(x-1,y-1,z);
		}
	}
	return 0;
}
