#include <cstdio>
char Abacus[8][8];
inline int calRow(int r)
{
	int ret = 0;
	if(Abacus[0][r]=='|')	ret += 5;
	for(int j=3;j<8;++j){
		if(Abacus[j][r]=='|'){
			ret+=j-3;
		}
	}
	int k=5-r;
	while(k--){
		ret*=10;
	}
//	printf("%d ",ret);
	return ret;
}
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		for(int i=0;i<8;++i)
			scanf("%s",Abacus[i]);
		int res=0;
		for(int i=0;i<6;++i)
			res+=calRow(i);
		for(int i=a;i<=b;++i)
			res-=i;
		if(res==0)	printf("No mistake\n");
		else		printf("Mistake\n");
	}
	return 0;
}