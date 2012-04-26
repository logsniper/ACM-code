#include <cstdio>

int create_array(int N,int S,int W,int* a){
	int g = S; 
	for (int i=0; i<N; i++) { 
    	a[i] = g;
    	if( a[i] == 0 ) { a[i] = g = W; }
    	if( g%2 == 0 ) { g = (g/2); }
    	else           { g = (g/2) ^ W; }
	}
	return 0;
}

int a[100000];

int main(){
	while(true){
		int N,S,W;
		scanf("%d%d%d",&N,&S,&W);
		create_array(N,S,W,a);
		for(int i=0;i<N;++i){
			printf("%d\t",a[i]);
		}
		printf("\n");
	}
}
