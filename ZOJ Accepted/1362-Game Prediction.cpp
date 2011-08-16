#include<iostream>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

bool bsearch(int target,int a[],int n)
{
	int first=0,last=n-1,mid;
	while(first<=last){
		mid=(first+last)/2;
		if(a[mid]==target)	return 1;
		else if(target>a[mid])	last=mid-1;
		else first=mid+1;
	}
	return 0;
}

int main()
{
	int m,n;
	int i,j,k;
	int card[50],other_card[50];
	int win_times;
	int exp=0;
	int max,min;
	while(cin>>m>>n&&(m!=0||n!=0)){
		exp++;
		k=1;
		win_times=0;
		for(i=0;i<n;i++)	cin>>card[i];
		qsort(card,n,sizeof(int),comp);
		for(k=m*n,j=0;k>=(m-2)*n&&j<n;k--){
			if(bsearch(k,card,n))	continue;
			other_card[j]=k;
			j++;
		}
		qsort(other_card,n,sizeof(int),comp);
		max=0;min=n-1;
		for(i=0;i<n;i++){
//			cout<<other_card[i]<<" ";
			if(card[i]>other_card[max]){
				win_times++;
				min--;
			}
			else{
				max++;
			}
		}
		cout<<"Case "<<exp<<": "<<win_times<<endl;
	}
	return 0;
}
