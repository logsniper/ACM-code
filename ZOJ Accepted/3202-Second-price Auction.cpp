#include<cstdio>
int main()
{
	int T,N,bid;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int firstprice=0,secondprice=0,winner,i;
		for(int i=0;i<N;i++){
			scanf("%d",&bid);
			if(bid>firstprice){
				winner=i+1;
				secondprice=firstprice;
				firstprice=bid;
			}
			else if(bid>secondprice)
				secondprice=bid;
		}
		printf("%d %d\n",winner,secondprice);
	}
	return 0;
}
