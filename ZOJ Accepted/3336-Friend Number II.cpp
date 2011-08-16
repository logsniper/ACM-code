#include <cstdio>
#include <ctime>
#include <cstring>
#include <assert.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	//	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);z
	string str;
	int T;
	cin>>T;
	while(T--){
		cin>>str;
		int len = str.length();
		int pos=-1;
		int sum = 0;
		for(int i=len-1;i>=0;--i){
			if(sum > 0 && str[i]<'9'){
				pos = i;
				break;
			}
			sum += str[i] - '0';
		}
		if(pos <0){
			str = "0" + str;
			pos = 0;
			++len;
		}
		str[pos] ++;
		--sum;
		for(int i=len-1;i>pos;--i){
			if(sum>9){
				str[i] = '9';
				sum -= 9;
			}
			else{
				str[i] = '0' + sum;
				sum = 0;
			}
		}
		cout<<str<<endl;
	}

	return 0;
}