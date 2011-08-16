#include<iostream>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int bsrch(int tmp,int fuck[],int N){
	int first,last,mid;
	first=0;last=N-1;
	while(first<=last){
		mid=(first+last)/2;
		if(tmp>fuck[mid])	first=mid+1;
		else if(tmp<fuck[mid])	last=mid-1;
		else return mid;
	}
	return -1;
}
int main()
{
	int fuck[1000];
	int N,i,j,p,q,flag,tmp;
	long long a,b;
	while(cin>>N&&N!=0){
		flag=0;
		for(i=0;i<N;i++)	cin>>fuck[i];
		qsort(fuck,N,sizeof(int),comp);
		for(q=N-1;q>=0;q--){
			for(i=0;i<N;i++)
				for(j=i+1;j<N;j++){
					if(q==i||q==j) continue;
					tmp=fuck[q]-fuck[i]-fuck[j];
					p=bsrch(tmp,fuck,N);
					if(p!=-1&&p!=q&&p!=i&&p!=j&&q!=i&&q!=j){
						flag=1;
						goto OUT;
					}
				}
		}
OUT	:	if(flag)	cout<<fuck[q]<<endl;
		else		cout<<"no solution\n";
	}
	return 0;
}
