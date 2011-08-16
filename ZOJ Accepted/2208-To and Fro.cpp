#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char from[204];
	char to[204];
	char course[200][204];
	int column;
	while(scanf("%d",&column)&&column!=0){
		scanf("%s",from);
		int len=strlen(from);
		int row=len/column;
		int yi,xi,k=0;
		for(yi=0;yi<row;yi++){
			if(yi%2==0)
				for(xi=0;xi<column;xi++)
					course[yi][xi]=from[k++];
			else
				for(xi=column-1;xi>=0;xi--)
					course[yi][xi]=from[k++];
		}
		k=0;
		for(xi=0;xi<column;xi++)
			for(yi=0;yi<row;yi++)
				to[k++]=course[yi][xi];
		to[k]='\0';
		printf("%s\n",to);
	}
	return 0;
}
