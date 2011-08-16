#include<cstdio>
#include<cstring>
#define MAXN 5000

int n;
int numbers[MAXN];
int copy[MAXN];
int buffer[MAXN];
int gao(int s,int e){
	if(s>=e)	return 0;
	if(s+1==e){
		if(numbers[s]>numbers[e]){
			int t = numbers[s];
			numbers[s] = numbers[e];
			numbers[e] = t;
			return 1;
		}
		else return 0;
	}
	int m = (s+e)/2;
	int res = gao(s,m) + gao(m+1,e);
	int p = 0;
	int i=s,j=m+1;
	for(int k=0;i<=m||j<=e;++k){
		if(j>e || (j<=e&&i<=m&&numbers[i]<numbers[j])){
			buffer[k] = numbers[i];
			res += p;
			++i;
		}
		else if(i>m || (j<=e&&i<=m&&numbers[i]>numbers[j])){
			buffer[k] = numbers[j];
			++p;
			++j;
		}
	}
	memcpy(&numbers[s],buffer,(e-s+1)*sizeof(int));
	return res;
/*	printf("%d %d\n",s,e);
	for(int i=s;i<=e;++i)	printf("%d ",numbers[i]);
	printf("\n");
	for(int i=0;i<e-s+1;++i)	printf("%d ",buffer[i]);
	printf("\n");*/
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i)	scanf("%d",&numbers[i]);
		memcpy(copy,numbers,sizeof numbers);
		int res = gao(0,n-1);
		int min = res;
		for(int i=0;i<n;++i){
			res = res - copy[i] + n-1-copy[i];
			if(min > res)	min = res;
		}
		printf("%d\n",min);
	}
	return 0;
}
