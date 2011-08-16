#include<cstdio>
#include<cstring>
#define MAX 300
#define LENGTH 10000
using namespace std;

int OPT(char a[],char b[],int value[])
{
	int opt[2][LENGTH];
	int len_a=strlen(a),len_b=strlen(b);
	int i,j;
	for(i=0;i<=len_a;i++)
		opt[0][i]=0;
	for(j=1;j<=len_b;j++){
		opt[1][0]=0;
		for(i=1;i<=len_a;i++){
			if(a[i-1]==b[j-1])
				opt[1][i]=opt[0][i-1]+value[int(a[i-1])];
			else{
				int s1=opt[0][i],s2=opt[1][i-1];
				opt[1][i]=s1>s2?s1:s2;
			}
		}
		for(i=0;i<=len_a;i++){
//			printf("%d ",opt[1][i]);
			int tmp=opt[0][i];
			opt[0][i]=opt[1][i];
			opt[1][i]=tmp;
		}
//		printf("\n");
	}
	return opt[0][len_a];
}

int main()
{
	int N,value[MAX],i;
	char a[LENGTH],b[LENGTH];
	while(scanf	("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			char c;
			int score;
			getchar();
			scanf("%c%d",&c,&score);
			value[int(c)]=score;
		}
		scanf("%s%s",a,b);
		int ans=OPT(a,b,value);
		printf("%d\n",ans);
	}
	return 0;
}
