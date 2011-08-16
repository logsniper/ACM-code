#include<cstdio>
using namespace std;
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
typedef struct Num{
	int pair[19];
	int pair_num;
	int now_pair;
	bool used;
}Num;
Num num[20];
bool bsearch_in_prime(int k)
{
	int first=0,last=11,mid;
	while(first<=last){
		mid=(first+last)/2;
		if(prime[mid]==k)	return true;
		if(k<prime[mid])	last=mid-1;
		else	first=mid+1;
	}
	return false;
}
void initialize(int n)
{
	int i,j;
	for(i=1;i<=n;i++){
		num[i].pair_num=0;
		num[i].now_pair=0;
		num[i].used=false;
	}
	num[1].used=true;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(bsearch_in_prime(i+j)&&i!=j){
				int k=num[i].pair_num;
				num[i].pair[k]=j;
				num[i].pair_num++;
			}
		}
}
bool next(int k){
	int i;
	for(i=num[k].now_pair;i<num[k].pair_num;i++)
		if(num[num[k].pair[i]].used==false)	return true;
	return false;
}
void find(int n)
{
	int a[n+1];
	int i,j,tmp;
	int total=0;
	bool end=false;
	a[0]=1;a[n]=1;
	while(1){
		for(i=1;i<n;i++){
			for(;num[a[i-1]].now_pair<num[a[i-1]].pair_num;num[a[i-1]].now_pair++){
				tmp=num[a[i-1]].pair[num[a[i-1]].now_pair];
				if(num[tmp].used==false){
					a[i]=tmp;
					num[tmp].used=true;
					break;
				}
			}
			if(i==n-1&&bsearch_in_prime(a[i]+1)&&num[a[i]].used==true){
//				printf("%d : ",++total);
				for(j=0;j<n;j++){
					printf("%d",a[j]);
					if(j<n-1)	printf(" ");
				}
				printf("\n");
				num[a[n-1]].used=false;
				num[a[n-1]].now_pair=0;
				num[a[n-2]].now_pair++;
				i--;
			}
			while(next(a[i])==false&&i>=1){
				num[a[i]].used=false;
				num[a[i]].now_pair=0;
				num[a[i-1]].now_pair++;
				i--;
			}
			if(i==0){
				if(next(1)==false){
					end=true;
					break;
				}
			}
		}
		if(end) break;
	}
}

int main()
{
	int n;
	int now=0;
	while(scanf("%d",&n)!=EOF){
		printf("Case %d:\n",++now);
		if(n%2==0){
			initialize(n);
			find(n);
		}
		printf("\n");
	}
	return 0;
}
