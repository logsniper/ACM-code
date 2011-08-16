#include<cstdio>
using namespace std;
int main()
{
	char OriginalCity[20],DistanceCity[20];
	int ActualMiles,summary;
	int i,j,k;
	char ClassCode[2],tmp;
	while(1){
		summary=0;
		while(1){
			scanf("%c",&tmp);
			if(tmp=='0'||tmp=='#')	break;
			while(tmp!=' ') scanf("%c",&tmp);
			scanf("%c",&tmp);
			while(tmp!=' ') scanf("%c",&tmp);
			scanf("%d%s",&ActualMiles,ClassCode);
			switch(ClassCode[0]){
				case 'F' :
					summary+=ActualMiles*2;
					break;
				case 'B' :
					summary+=ActualMiles;
					ActualMiles++;
					summary+=ActualMiles*0.5;
					break;
				case 'Y' :
					if(ActualMiles<500)	summary+=500;
					else	summary+=ActualMiles;
					break;
			}
			getchar();
		}
		getchar();
		if(tmp=='#')	break;
		printf("%d\n",summary);
	}
	return 0;
}
