#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int N,n;
	float p,result;
	char tt[4][3];
	char xx[3],yy[3];
	tt[0][0]='k';tt[0][1]='g';tt[0][2]='\0';
	tt[1][0]='l';tt[1][1]='b';tt[1][2]='\0';
	tt[2][0]='l';tt[2][1]='\0';
	tt[3][0]='g';tt[3][1]='\0';
	scanf("%d",&N);
	for(n=1;n<=N;n++){
		scanf("%f%s",&p,xx);
		if(strcmp(xx,tt[0])==0){
			result=p*2.2046;
			yy[0]='l';yy[1]='b';yy[2]='\0';
		}
		else if(strcmp(xx,tt[1])==0){
			result=p*0.4536;
			yy[0]='k';yy[1]='g';yy[2]='\0';
		}
		else if(strcmp(xx,tt[2])==0){
			result=p*0.2642 ;
			yy[0]='g';yy[1]='\0';
		}
		else if(strcmp(xx,tt[3])==0){
			result=p*3.7854;
			yy[0]='l';yy[1]='\0';
		}
		printf("%d %.4f %s\n",n,result,yy);
	}
	return 0;
}
