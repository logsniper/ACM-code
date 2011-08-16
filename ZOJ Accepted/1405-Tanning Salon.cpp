#include<cstdio>
using namespace std;
int main()
{
	int n,left,i;
	bool judge[26];
	char now;
	while(scanf("%d",&n)&&n!=0){
		left=0;
		for(i=0;i<26;i++)
			judge[i]=0;
		while(scanf("%c",&now)&&now!='\n'){
			if(now<'A'||now>'Z')	continue;
			if(judge[now-'A']==1){
				n++;
				judge[now-'A']=0;
			}
			else if(n!=0){
				n--;
				judge[now-'A']=1;
			}
			else left++;
		}
		if(left==0)	printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",left/2);
	}
	return 0;
}
