#include<cstdio>
int table[8][8];
int startx,starty;
int endx,endy;

bool move(int i,int j)
{
	int step=table[i][j];
	if(i-2>=0&&j+1<8&&table[i-2][j+1]==-1)
		table[i-2][j+1]=step+1;
	if(i-1>=0&&j+2<8&&table[i-1][j+2]==-1)
		table[i-1][j+2]=step+1;
	if(i+1<8&&j+2<8&&table[i+1][j+2]==-1)
		table[i+1][j+2]=step+1;
	if(i+2<8&&j+1<8&&table[i+2][j+1]==-1)
		table[i+2][j+1]=step+1;
		
	if(i-2>=0&&j-1>=0&&table[i-2][j-1]==-1)
		table[i-2][j-1]=step+1;
	if(i-1>=0&&j-2>=0&&table[i-1][j-2]==-1)
		table[i-1][j-2]=step+1;
	if(i+1<8&&j-2>=0&&table[i+1][j-2]==-1)
		table[i+1][j-2]=step+1;
	if(i+2<8&&j-1>=0&&table[i+2][j-1]==-1)
		table[i+2][j-1]=step+1;
	if(table[endx][endy]!=-1)	return false;
	else return true;
}

void stepnum()
{
	bool goon;
	int step=0;
	while(1){
		int i,j;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++){
				if(table[i][j]==step){
					goon=move(i,j);
					if(goon==false)	return;
				}
			}
		step++;
/*		for(i=0;i<8;i++){
			for(j=0;j<8;j++)
				printf("%d ",table[i][j]);
			printf("\n");
		}*/
	}
}

int main()
{
	char a[3],b[3];
	while(scanf("%s%s",a,b)!=EOF){
		startx=a[0]-'a',starty=a[1]-'1';
		endx=b[0]-'a',endy=b[1]-'1';
		int i,j;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				table[i][j]=-1;
		table[startx][starty]=0;
		stepnum();
		printf("To get from %s to %s takes %d knight moves.\n",a,b,table[endx][endy]);
	}
	return 0;
}
