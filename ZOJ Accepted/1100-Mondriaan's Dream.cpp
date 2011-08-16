#include<cstdio>
#include<cstring>
int h,w;
long long dp[12][2050];
bool valid[2050][2050];
bool applybuf[2050][2050];
bool apply(int mod,int st){
	if(valid[mod][st])	return applybuf[mod][st];
	applybuf[mod][st] = false;
	valid[mod][st] = true;
	if((st&mod) < mod){
		return false;
	}
	int st2 = (st^mod);
	for(int i=0;i<w;++i){
		if((st2&(1<<i)) > 0){
			++i;
			if(i==w || ((st2&(1<<i))==0)){
				return false;
			}
		}
	}
	applybuf[mod][st] = true;
	return true;
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&h,&w) && h>0){
		memset(dp,0,sizeof dp);
		memset(valid,0,sizeof valid);
		
		int full = (1<<w)-1;
		for(int st=0;st<=full;++st){
			if(apply(0,st))	dp[1][st] = 1;
		}
		for(int hi=1;hi<h;++hi){
			for(int st=0;st<=full;++st){
				if(dp[hi][st] == 0)	continue;
				int nextrow = full - st;
				for(int nst=0;nst<=full;++nst){
					if(apply(nextrow,nst)){
						dp[hi+1][nst] += dp[hi][st];
					}
				}
			}
		}
		
/*		for(int i=1;i<=h;++i){
			for(int j=0;j<=full;++j){
				printf("%lld ",dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%lld\n",dp[h][full]);
	}
}
