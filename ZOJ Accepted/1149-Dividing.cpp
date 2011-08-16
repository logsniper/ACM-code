#include<cstdio>
using namespace std;

bool f(int x[])
{
	int y[6],k[6],i;
	for(i=0;i<6;i++){
		if(x[i]>60/(i+1))	k[i]=60/(i+1)+x[i]%2;
		else k[i]=x[i];
	}
	for(y[1]=-k[1];y[1]<=k[1];y[1]+=2)
		for(y[2]=-k[2];y[2]<=k[2];y[2]+=2)
			for(y[3]=-k[3];y[3]<=k[3];y[3]+=2)
				for(y[4]=-k[4];y[4]<=k[4];y[4]+=2)
					for(y[5]=-k[5];y[5]<=k[5];y[5]+=2){
						y[0]=-(2*y[1]+3*y[2]+4*y[3]+5*y[4]+6*y[5]);
						if(y[0]>=-x[0]&&y[0]<=x[0]&&(x[0]-y[0])%2==0){
//							printf("%d %d %d %d %d %d\n",y[0],y[1],y[2],y[3],y[4],y[5]);
							return 1;
						}
					}
	return 0;
}

int main()
{
	int x[6],cas=0;
	while(1){
		cas++;
		int i,Allzero=1;
		for(i=0;i<6;i++){
			scanf("%d",&x[i]);
			if(x[i]>0)	Allzero=0;
		}
		if(Allzero)	break;
		printf("Collection #%d:\n",cas);
		if((x[0]+x[2]+x[4])%2==0&&f(x))	printf("Can be divided.\n\n");
//		if(f(x))	printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");

	}
	return 0;
}
