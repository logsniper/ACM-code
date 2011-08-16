#include<cstdio>
#define MAX (1<<30)
int basket[41][41][41][41];
int piles[4][41];
int n;
int countBasket(int bsk){
	if(bsk == MAX)	return MAX;
	int mask=31,c=0;
	for(int i=0;i<5;++i){
		if((bsk&mask) > 0)	++c;
		mask <<= 5;
	}
	return c;
}
int putIntoBasket(int bsk,int color){
	if(bsk == MAX)	return MAX;
	int c,mask=31,emptypos=-1;
	if(countBasket(bsk) == 5)	return MAX;
	for(int i=0;i<5;++i){
		int p = (bsk&mask);
		c = color<<(i*5);
		if(p==c){
			return bsk^c;
		}
		else if(p==0){
			emptypos = i*5;
		}
		mask <<= 5;
	}
	if(emptypos>=0){
		return bsk|(color<<emptypos);
	}
	else{
		return MAX;
	}
}
void printBasket(int bsk){
	int mask=31,c=0;
	printf("%d : ",bsk);
	for(int i=0;i<5;++i){
		if((bsk&mask) > 0)	++c;
		printf("%d ",(bsk&mask)>>(i*5));
		mask <<= 5;
	}
	printf("\n");
}
int getDP(int c1,int c2,int c3,int c4){
	if(basket[c1][c2][c3][c4] != -1)	return basket[c1][c2][c3][c4];
	basket[c1][c2][c3][c4] = MAX;
	if(c1>0&&basket[c1][c2][c3][c4]==MAX){
		int b = putIntoBasket(getDP(c1-1,c2,c3,c4),piles[0][c1]);
		if(basket[c1][c2][c3][c4] > b)	basket[c1][c2][c3][c4] = b;
	}
	if(c2>0&&basket[c1][c2][c3][c4]==MAX){
		int b = putIntoBasket(getDP(c1,c2-1,c3,c4),piles[1][c2]);
		if(basket[c1][c2][c3][c4] > b)	basket[c1][c2][c3][c4] = b;
	}
	if(c3>0&&basket[c1][c2][c3][c4]==MAX){
		int b = putIntoBasket(getDP(c1,c2,c3-1,c4),piles[2][c3]);
		if(basket[c1][c2][c3][c4] > b)	basket[c1][c2][c3][c4] = b;
	}
	if(c4>0&&basket[c1][c2][c3][c4]==MAX){
		int b = putIntoBasket(getDP(c1,c2,c3,c4-1),piles[3][c4]);
		if(basket[c1][c2][c3][c4] > b)	basket[c1][c2][c3][c4] = b;
	}
	return basket[c1][c2][c3][c4];
}
int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)&&n>0){
		for(int i=1;i<=n;++i){
			scanf("%d%d%d%d",&piles[0][i],&piles[1][i],&piles[2][i],&piles[3][i]);
		}
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					for(int t=0;t<=n;++t){
						basket[i][j][k][t] = -1;
					}
				}
			}
		}
		basket[1][0][0][0] = putIntoBasket(0,piles[0][1]);
		basket[0][1][0][0] = putIntoBasket(0,piles[1][1]);
		basket[0][0][1][0] = putIntoBasket(0,piles[2][1]);
		basket[0][0][0][1] = putIntoBasket(0,piles[3][1]);
	
		int max = 0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					for(int t=0;t<=n;++t){
//						printf("%d %d %d %d %d\n",i,j,k,t,getDP(i,j,k,t));
						int get = (i+j+k+t-countBasket(getDP(i,j,k,t)))/2;
						if(max < get){
							max = get;
//							printf("MAX:\n");
//							printBasket(getDP(i,j,k,t));
//							printf("%d %d %d %d %d\n",i,j,k,t,countBasket(getDP(i,j,k,t)));
						}
					}
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
