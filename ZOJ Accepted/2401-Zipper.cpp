#include<cstdio>
#include<cstring>
char a[204],b[204],c[404];
int alen,blen,clen;
int dfstable[1000][1000];
bool dfs(int ai,int bi,int ci)
{
	if(dfstable[ai][bi]!=-1)
		return dfstable[ai][bi];
	bool ret;
	if(ci==clen-1){
		if(ai==alen&&b[bi]==c[ci])	ret = true;
		else if(bi==blen&&a[ai]==c[ci])	ret = true;
		else ret = false;
	}
	else if(ai==alen){
		if(c[ci]!=b[bi])	ret = false;
		else	ret = dfs(ai,bi+1,ci+1);
	}
 	else if(bi==blen){
		if(c[ci]!=a[ai])	ret = false;
		else 	ret = dfs(ai+1,bi,ci+1);
	}
	else if(ai<alen&&bi<blen){
		if(c[ci]!=b[bi]&&c[ci]!=a[ai])	ret = false;
		else if(c[ci]==b[bi]&&c[ci]!=a[ai])
			ret = dfs(ai,bi+1,ci+1);
		else if(c[ci]!=b[bi]&&c[ci]==a[ai])
			ret = dfs(ai+1,bi,ci+1);
		else ret = dfs(ai,bi+1,ci+1) || dfs(ai+1,bi,ci+1);
	}
	dfstable[ai][bi] = ret;
	return ret;
}
int main()
{
	int N,n;
	int ai,bi,ci;
	scanf("%d",&N);
	for(n=1;n<=N;++n){
		scanf("%s%s%s",a,b,c);
		alen=strlen(a),blen=strlen(b),clen=strlen(c);
		for(int i=0;i<=alen;++i)
			for(int j=0;j<=blen;++j)
				dfstable[i][j]=-1;
		if(alen+blen==clen&&dfs(0,0,0))
			printf("Data set %d: yes\n",n);
		else
			printf("Data set %d: no\n",n);
	}
	return 0;
}
