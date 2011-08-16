#include<cstdio>
double cal(int p,int q,int r,int s)
{
	double res = 1.0f;
	int up[3]={p,s,r-s};
	int down[3]={r,q,p-q};
	int pup=0,pdown=0,i=1,j=1;
	while(true){
		if(i>up[pup]){
			i=1;
			++pup;
		}
		if(j>down[pdown]){
			j=1;
			++pdown;
		}
		if(pup>2)	break;
		if(pdown>2)	break;
		if(res>100000000){
			res/=(double)j;
			++j;
		}
		else if(res<0.00001){
			res*=i;
			++i;
		}
		else{
			res*=(double)i/j;
			++i,++j;
		}
	}
	while(pup<2||i<=up[2]){
		if(i>up[pup]){
			i=1;
			++pup;
		}
		if(pup>2)	break;
		res*=i;
		++i;
	}
	while(pdown<2||j<=down[2]){
		if(j>down[pdown]){
			j=1;
			++pdown;
		}
		if(pdown>2)	break;
		res/=(double)j;
		++j;
	}
	return res;
}

int main()
{
	int p,q,r,s;
	while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF){
		printf("%.5lf\n",cal(p,q,r,s));
	}
	return 0;
}
