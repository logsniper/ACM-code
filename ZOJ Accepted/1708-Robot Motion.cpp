#include<cstdio>
char map[11][11];
int round[11][11];
int r,l,enter;

void init()
{
	for(int i=0;i<r;++i)
		scanf("%s",map[i]);
	for(int i=0;i<=r;++i)
		for(int j=0;j<=l;++j)
			round[i][j]=0;
}

bool go()
{
	int x=enter,y=1,step=0;
	while(true){
		++step;
//		printf("%d %d %d %c %d\n",y,x,step,map[y-1][x-1],round[y][x]);
		if(x==0||x==l+1||y==0||y==r+1){
			printf("%d step(s) to exit\n",step-1);
			return true;
		}
		if(round[y][x]>0){
			printf("%d step(s) before a loop of %d step(s)\n",round[y][x]-1,step-round[y][x]);
			return false;
		}
		round[y][x]=step;
		switch(map[y-1][x-1]){
			case 'N' : --y;break;
			case 'S' : ++y;break;
			case 'W' : --x;break;
			case 'E' : ++x;break;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&r,&l,&enter)&&r*r+l*l+enter*enter!=0){
		init();
		go();
	}
	return 0;
}
