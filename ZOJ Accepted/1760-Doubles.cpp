#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[15];
	int n;
	int tmp;
	while(scanf("%d",&tmp)&&tmp!=-1){
		a[0]=tmp;
		n=1;
		for(int i=1;a[i-1]!=0;i++){
			scanf("%d",&a[i]);
			n++;
		}
		n--;
		int num=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(a[j]==a[i]*2) {
					num++;
					continue;
				}
		cout<<num<<endl;
	}
}
