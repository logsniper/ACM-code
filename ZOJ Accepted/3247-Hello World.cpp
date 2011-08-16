#include <cstdio>
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	char output[7][480];
	int cas;
	scanf("%d",&cas);
	for(int c=1;c<=cas;++c){
		int line;
		scanf("%d",&line);
		for(int i=0;i<7;++i){
			for(int j=0;j<6*line;++j)
				output[i][j]=' ';
			output[i][6*line-1]='\0';
		}
		int num[5];
		for(int i=0;i<line;++i){
			for(int j=0;j<5;++j){
				scanf("%x",&num[j]);
				for(int k=0;k<7;++k){
					if(num[j] & 1){
						output[k][6*i+j]='#';
					}
					num[j]/=2;
				}
			}
		}
		printf("Case %d:\n\n",c);
		for(int i=0;i<7;++i)
			printf("%s\n",output[i]);
		printf("\n");
	}
	return 0;
}