#include<cstdio>
#include<cstring>
#define MIN (-(1<<30));
int n;
int matrix[20][20][20];
int sum[20][20][20];
int array[20];
int initialize(){
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&matrix[k][i][j]);
			}
		}
	}
	for(int k=0;k<n;++k){
		sum[k][0][0] = matrix[k][0][0];
		for(int i=1;i<n;++i){
			sum[k][0][i] = sum[k][0][i-1]+matrix[k][0][i];
			sum[k][i][0] = sum[k][i-1][0]+matrix[k][i][0];
		}
		for(int i=1;i<n;++i)	for(int j=1;j<n;++j){
			sum[k][i][j] = sum[k][i-1][j]+sum[k][i][j-1]
					-sum[k][i-1][j-1]+matrix[k][i][j];
		}
	}
}

int getMaxSegment(int ai,int aj,int bi,int bj){
	for(int k=0;k<n;++k){
		array[k] = sum[k][bi][bj];
		if(ai>0)	array[k]-=sum[k][ai-1][bj];
		if(aj>0)	array[k]-=sum[k][bi][aj-1];
		if(ai>0&&aj>0)	array[k]+=sum[k][ai-1][aj-1];
	}
	int max=MIN;
	int sum=0;
	for(int k=0;k<n;++k){
		sum += array[k];
		if(max < sum)	max = sum;
		if(sum < 0)		sum = 0;
	}
	return max;
}

int gerResult(){
	int res = MIN;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int p=i;p<n;++p){
				for(int q=j;q<n;++q){
					int t = getMaxSegment(i,j,p,q);
					if(res < t)	res = t;
				}
			}
		}
	}
	return res;
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF && n>0){
		initialize();
		printf("%d\n",gerResult());
	}
	return 0;
}
