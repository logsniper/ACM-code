#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N,t;
	char correct[84],now[84];
	int length_c,length_n,i;
	int ans;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&t);
		getchar();
		i=-1;
		do{
			i++;
			scanf("%c",correct+i);
		}while(correct[i]!='\n');
		correct[i]='\0';
		i=-1;
		do{
			i++;
			scanf("%c",now+i);
		}while(now[i]!='\n');
		now[i]='\0';
//		printf("%s %s",correct,now);
		length_c=strlen(correct);
		length_n=strlen(now);
		for(i=0;i<length_n;i++){
			if(correct[i]!=now[i])	break;
		}
		ans=t*(length_n-i+length_c-i);
		printf("%d\n",ans);
	}
	return 0;
}
