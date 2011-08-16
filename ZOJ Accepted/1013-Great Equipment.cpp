#include<cstdio>
#include<cstring>
int n;
int w[3],s[3],d[3];
int c1,c2,c3,d4;
int ww[100],ss[100];
int dp[2][501][501];
int max3(int id,int count1,int count2){
	int wleft = ww[id] - count1*w[0] - count2*w[1];
	int sleft = ss[id] - count1*s[0] - count2*s[1];
	if(wleft < 0 || sleft < 0)	return -1;
	int ret = 1000;
	if(ret > wleft/w[2])	ret = wleft/w[2];
	if(ret > sleft/s[2])	ret = sleft/s[2];
	return ret;
}
int max3buf[501][501];

int calDeffence(int a,int b,int c){
	int num=1000;
	if(num > a/c1)	num = a/c1;
	if(num > b/c2)	num = b/c2;
	if(num > c/c3)	num = c/c3;
 	a -= num*c1;
 	b -= num*c2;
 	c -= num*c3;
 	return num*d4+a*d[0]+b*d[1]+c*d[2];
}
int main(){
//	freopen("in.txt","r",stdin);
	int cas = 0;
	while(scanf("%d",&n) && n>0){
		++cas;
		for(int i=0;i<3;++i){
			scanf("%d%d%d",&w[i],&s[i],&d[i]);
		}
		scanf("%d%d%d%d",&c1,&c2,&c3,&d4);
		for(int i=0;i<n;++i){
			scanf("%d%d",&ww[i],&ss[i]);
		}
		for(int i=0;i<=500;++i){
			for(int j=0;j<=500;++j){
				dp[0][i][j] = -1;
			}
		}
		int wcost0=0,scost0=0;
		for(int i=0;;++i){
			if(wcost0>ww[0] || scost0>ss[0])	break;
			int wcost1=0,scost1=0;
			for(int j=0;;++j){
				if(wcost0+wcost1>ww[0] || scost0+scost1>ss[0])	break;
				dp[0][i][j] = max3(0,i,j);
				wcost1 += w[1];
				scost1 += s[1];
			}
			wcost0 += w[0];
			scost0 += s[0];
		}
		int id = 1,array = 1;
		int wtotal = ww[0], stotal = ss[0];
		for(array=1;id<n;++id,array = 1-array){
			wtotal += ww[id], stotal += ss[id];
			for(int i=0;i<=500;++i){
				for(int j=0;j<=500;++j){
					max3buf[i][j] = max3(id,i,j);
					dp[array][i][j] = -1;
				}
			}
			for(int ii=0;ii<=500;++ii){
				if(w[0]*ii > wtotal || s[0]*ii>stotal)	break;
				int wt = w[0]*ii,st = s[0]*ii;
				for(int jj=0;jj<=500;++jj){
					if(wt+w[1]*jj>wtotal || st+s[1]*jj>stotal)	break;

					int max = -1;
					int wcost0=0,scost0=0;
					for(int i=0;i<=ii;++i){
						if(wcost0>ww[id] || scost0>ss[id])	break;
						int wcost1=0,scost1=0;
						for(int j=0;j<=jj;++j){

							if(wcost0+wcost1>ww[id] || scost0+scost1>ss[id])	break;
							if(max3buf[i][j]<0)	break;
							if(dp[1-array][ii-i][jj-j]<0)continue;
							if(max < dp[1-array][ii-i][jj-j]+max3buf[i][j]){
								max = dp[1-array][ii-i][jj-j]+max3buf[i][j];
							}
							wcost1 += w[1];
							scost1 += s[1];
						}
						wcost0 += w[0];
						scost0 += s[0];
					}
					
					dp[array][ii][jj] = max;
					
				}
			}
		}
		
		int res = 0;
		array = 1-array;
		for(int i=0;i<=500;++i){
			for(int j=0;j<=500;++j){
				int ddd = calDeffence(i,j,dp[array][i][j]);
				if(dp[array][i][j]>=0 && res < ddd ){
					res = ddd;
//					printf("%d %d %d %d\n",i,j,dp[array][i][j],ddd);
				}
			}
		}
		if(cas>1)	printf("\n");
		printf("Case %d: %d\n",cas,res);
//		printf("%d %d\n",dp[1-array][1][0],max3(0,1,0));
	}
}
