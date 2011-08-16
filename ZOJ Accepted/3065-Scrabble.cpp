#include <cstring>
#include <cstdio>
char own[8];
int avail[26],left;
bool solve(char *a)
{
	int cnt[26],count=0;
	memset(cnt,0,sizeof(cnt));
	int len=strlen(a);
	for(int i=0;i<len;++i){
		++cnt[a[i]-'A'];
		if(cnt[a[i]-'A']>avail[a[i]-'A']){
			++count;
			if(count>left)	return false;
		}
	}
//	printf("%s count = %d\n",a,count);
	return true;
}
char dict[1000][8];
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,res;
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i)
			scanf("%s",dict[i]);
		scanf("%s",own);
		memset(avail,0,sizeof(avail));
		left=0;
		for(int i=0;i<strlen(own);++i){
			if(own[i]<='Z'&&own[i]>='A')	avail[own[i]-'A']++;
			else		++left;
		}
//		printf("left = %d\n",left);
		res=0;
		for(int i=0;i<n;++i){
			if(solve(dict[i]))		++res;
		}
		printf("%d\n",res);
	}
	return 0;
}