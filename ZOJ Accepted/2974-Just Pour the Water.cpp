#include <cstdio>
#define MAXN 24
double pour[34][MAXN][MAXN];

inline void multiply(int s1,int ar,int ac,int s2,int bc,int d)
{
	for(int i=0;i<ar;++i)
		for(int j=0;j<ar;++j){
			double sum=0.0f;
			for(int k=0;k<ac;++k)
				sum+=pour[s1][i][k]*pour[s2][k][j];
			pour[d][i][j]=sum;
		}
}

int main()
{
//	freopen("input.txt","r",stdin);
	double start[MAXN];
	double final[MAXN];
	int t,n,k,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf",&start[i]);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				pour[0][i][j]=0.0f;
				if(i==j)
					pour[32][i][j]=1.0f;
				else
					pour[32][i][j]=0.0f;
			}
			scanf("%d",&k);
			if(!k)//如果k==0，不倒水,一直wa在这个地方……
				pour[0][i][i]=1.0f;
			int tmp;
			for(int j=0;j<k;++j){
				scanf("%d",&tmp);
				pour[0][i][tmp-1]=1.0f/k;
			}
		}
		scanf("%d",&m);
		for(int i=0;i<30;++i)
			multiply(i,n,n,i,n,i+1);
		for(int degree=0;m>=1;++degree){
			if(m%2){
				multiply(32,n,n,degree,n,33);
				for(int i=0;i<n;++i)
					for(int j=0;j<n;++j)
						pour[32][i][j]=pour[33][i][j];
			}
			m/=2;
		}

		for(int i=0;i<n;++i){
			double sum=0.0f;
			for(int j=0;j<n;++j){
				sum+=start[j]*pour[32][j][i];
			}
			final[i]=sum;
		}
		for(int i=0;i<n;++i){
			if(i)	printf(" ");
			printf("%.2lf",final[i]);
		}
		printf("\n");
	}
	return 0;
}