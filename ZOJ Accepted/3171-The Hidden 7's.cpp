#include<cstdio>
#include<cstring>
int main()
{
	char sevens[10001];
	long long seven[5];
	while(scanf("%s",sevens)!=EOF){
		int i,len=strlen(sevens);
		memset(seven,0,5*sizeof(long long));
		for(i=0;i<len;i++){
			if(sevens[i]=='s'||sevens[i]=='S'){
				seven[0]++;
			}
			else if(sevens[i]=='e'||sevens[i]=='E'){
				seven[1]+=seven[0];
				seven[3]+=seven[2];
			}
			else if(sevens[i]=='v'||sevens[i]=='V'){
				seven[2]+=seven[1];
			}
			else if(sevens[i]=='n'||sevens[i]=='N'){
				seven[4]+=seven[3];
			}
		}
		printf("%lld\n",seven[4]);
	}
	return 0;
}
