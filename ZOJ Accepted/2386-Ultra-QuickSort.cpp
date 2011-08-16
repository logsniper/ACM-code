#include<cstdio>
#include<algorithm>
using namespace std;
int num[500000],n;
long long find(int s,int e)
{
	if(s==e)	return 0;
	if(s+1==e){
		if(num[s]>num[e])	return 1;
		else return 0;
	}
	int m=(s+e)/2;	
	long long ret = find(s,m) + find(m+1,e);

	int xn=m-s+1;
	int yn=e-m;
	sort(num+s,num+s+xn);
	sort(num+m+1,num+m+1+yn);

	int xp=0,yp=0,tp=0;
	for(yp=0;yp<yn;yp++){
		while(num[s+xp]<num[m+1+yp]&&xp<xn)	++xp;
		ret += (long long)xn-xp;
	}

	return ret;
}

int main()
{
//	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i)
			scanf("%d",num+i);
		long long res = find(0,n-1);
//		for(int i=0;i<n;++i)
//			printf("%d ",num[i]);
		printf("%lld\n",res);
	}
	return 0;
}
