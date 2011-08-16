#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define ABS(X) ((X)>0?(X):(-(X)))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
long long getN(int x,int y){
	int n = MAX(ABS(x),ABS(y));
	long long res = (2*n-1)*(2*n-1);
	if(x==n&&y>-n)	res += y+n;
	else{
		res += 2*n;
		if(y==n&&x<n)	res += n-x;
		else{
			res += 2*n;
			if(x==-n&&y<n)	res += n-y;
			else{
				res += 2*n;
				if(y==-n&&x>-n)	res += x+n;
				else	res += 2*n;
			}
		}
	}
	return res;
}

void getXY(int n,int &x,int &y){
	int k = (int)sqrt(n);
	if(k%2==0)	--k;
	int m = (k+1)/2;
	int left = n-k*k;
	if(left == 0){
		x = m-1;
		y = 1-m;
	}
	else if(left<=m*2){
		x = m;
		y = left-m;
	}
	else if(left<=m*4){
		y = m;
		x = 3*m-left;
	}
	else if(left<=m*6){
		x = -m;
		y = 5*m-left;
	}
	else if(left<=m*8){
		y = -m;
		x = left-7*m;
	}
}

int main()
{
	int n;
	int x,y;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		getXY(n,x,y);
		vector<int> res;
		res.push_back(getN(x-1,y));
		res.push_back(getN(x+1,y));
		res.push_back(getN(x,y-1));
		res.push_back(getN(x,y+1));
		sort(res.begin(),res.end());
		for(int i=0;i<4;++i){
			if(i)	printf(" ");
			printf("%d",res[i]);
		}
		printf("\n");
	}
	return 0;
}
