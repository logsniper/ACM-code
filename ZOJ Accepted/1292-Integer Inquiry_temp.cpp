#include<cstdio>
#include<cstring>
using namespace std;
void reverse(char a[],int n)
{
	int i;
	char c;
	for(i=0;i<=(n-1)/2;i++){
		c=a[n-1-i];
		a[n-1-i]=a[i];
		a[i]=c;
	}
}
int main()
{
	char VLI[101][105];
	char ans[105];
	int block,n,i,j,upto,L,max;
	scanf("%d",&block);
	while(block--){
		n=0;
		while(scanf("%s",VLI[n])&&!(VLI[n][0]=='0'&&strlen(VLI[n])==1)) n++;
		for(i=0;i<105;i++)	ans[i]='0';
		max=0;
		for(i=0;i<n;i++){
			L=strlen(VLI[i]);
			reverse(VLI[i],L);
			upto=0;
			for(j=0;j<L;j++){
				ans[j]+=VLI[i][j]-'0'+upto;
				if(ans[j]>'9'){
					upto=1;
					ans[j]-=10;
				}
				else upto=0;
			}
			while(upto){
				ans[j]+=1;
				if(ans[j]>'9'){
					upto=1;
					ans[j]-=10;
				}
				else upto=0;
				j++;
			}
			if(max<j)	max=j;
		}
		ans[max]='\0';
		reverse(ans,max);
		printf("%s\n",ans);
		if(block)	printf("\n");
	}
	return 0;
}
