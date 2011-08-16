#include<cstdio>
int main()
{
//	freopen("input.txt","r",stdin);
	int n,m,amount;
	int newone,M1[5000],M2[5000];
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF){
		amount=0;
		for(j=0;j<m;j++)
			M1[j]=0;
		int zero=0;
		for(i=0;i<n;i++){
			scanf("%d",&newone);
/*			for(j=0;j<m;j++)
				M2[(j+newone)%m]=M1[j];
			for(j=0;j<m;j++)
				M1[j]=M2[j];
			M1[newone%m]++;
			amount+=M1[0];*/
			zero=(zero+m-newone%m)%m;
			M1[(zero+newone)%m]++;
			amount+=M1[zero];
		}
		printf("%d\n",amount);
	}
	return 0;
}
