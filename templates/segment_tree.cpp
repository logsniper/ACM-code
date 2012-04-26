#include <cstdio>
#include <iostream>
using namespace std;
/*
template <class T> struct op{
	T operator() (const T& a, const T&b)const {
		return ...;
	}
};
*/
template<class T> struct maxT{
	T operator() (const T& a, const T& b)const {
		return a<b?b:a;
	}
};

const int MAXSIZE = 1000000;
template<class T, class optype = maxT<T> >
class segment_tree{
public:
	segment_tree(bool debug = false):debugOn(debug){}
	/*
	 * User must make sure that for any T x, x == op(x,_default) always hold
	 */
	int init(T *array, int sz, const T& _default){
		size = 1;
		while( size < sz){
			size <<= 1;
			if(size < 0 || size > MAXSIZE)	return 1;
		}
		for(int i=0;i<sz;++i) buffer[size + i] = array[i];
		for(int i = size + sz;i<(size<<1); ++i) buffer[i] = _default;
		for(int i=size-1;i>0;--i)	buffer[i] = op(buffer[i*2],buffer[i*2+1]);
		return 0;
	}

	void print(){
		for(int depth = 0;(1<<depth)<=size;++depth){
			int start = 1<<depth;
			int end = 1<<(depth+1);
			cout<<"["<<start<<","<<end<<") :\t";
			for(int i=start;i<end;++i){
				cout<<buffer[i]<<"\t";
			}
			cout<<endl;
		}
	}

	int query(int start,int end, T& out){
		return _query(start,end,1,out);
	}
	/*
	 * return calculated elements between start and end inclusive.
	 */
private:
	int _query(int start,int end,int index, T& out){
		int depth = 0;
		while((1<<(depth+1)) <= index){
			++ depth;
		}
		int seglength = size/(1<<depth);
		int mystart = seglength * (index - (1<<depth));
		int myend = mystart + seglength - 1;
		int retvalue = 0;
		if(debugOn)	printf("index : %d, depth : %d, query(%d,%d), actual range (%d,%d)\n",index,depth,start,end,mystart,myend);
		if(start < mystart || end > myend){
			if(debugOn) printf("[ERROR]\tindex : %d, depth : %d, query(%d,%d), actual range (%d,%d)\n",index,depth,start,end,mystart,myend);
			retvalue = 1;
		}
		else if(start == mystart && end == myend){
			out = buffer[index];
		}
		else if(end < mystart + (seglength>>1) ){
			retvalue = _query(start,end,2*index,out);
		}
		else if(start >= mystart + (seglength>>1) ){
			retvalue = _query(start,end,2*index+1,out);
		}
		else{
			T x,y;
			if(0 == _query(start,mystart+(seglength>>1)-1,2*index,x)
					&& 0 == _query(mystart+(seglength>>1),end,2*index+1,y)){
				out = op(x,y);
			} else {
				retvalue = 1;
			}
		}
		return retvalue;
	}

private:
	bool debugOn;
	optype op;
	T buffer[MAXSIZE*2];
	int size;
};

int array[100000];
int main(){
	class segment_tree<int> st(1);
	for(int i=0;i<100000;++i){
		array[i] = i;
	}
	int ret = st.init(array,100000,0);
	cout << ret << endl;
	//st.print();

	int res;
	ret = st.query(0,50000,res);
	cout << "return value = " << ret << ", result = " << res << endl;
}
