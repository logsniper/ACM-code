#include <cstdio>
#include <cstring>
int main()
{
	int T;
	int p,pa,pb;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&p,&pa,&pb);
		printf("%s\n",pa<pb?"B":"A");
	}
	return 0;
}