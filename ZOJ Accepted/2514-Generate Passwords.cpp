#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int N,M,k,length;
	int i;
	char name[1000][11],password[1000][11];
	bool flag_N1,flag_N2,flag_N3,flag_pw[1000];
	while(scanf("%d",&N)&&N!=0){
		k=N;
		M=0;
		flag_N2=0;
		flag_N3=0;
		for(k=0;k<N;k++){
			scanf("%s %s",name[k],password[k]);
			length=strlen(password[k]);
			flag_N1=0;
			flag_pw[k]=0;
			for(i=0;i<length;i++){
				if(password[k][i]=='1')			{password[k][i]='@';flag_N1=1;flag_N3=1;flag_pw[k]=1;}
				else if(password[k][i]=='0')	{password[k][i]='%';flag_N1=1;flag_N3=1;flag_pw[k]=1;}
				else if(password[k][i]=='l')	{password[k][i]='L';flag_N1=1;flag_N3=1;flag_pw[k]=1;}
				else if(password[k][i]=='O')	{password[k][i]='o';flag_N1=1;flag_N3=1;flag_pw[k]=1;}
			}
			if(flag_N1)	M++;
		}
		
		for(k=0;k<N;k++){
			if(flag_N3&&!flag_N2){
				printf("%d\n",M);
				flag_N2=1;
			}
			if(flag_pw[k])
				printf("%s %s\n",name[k],password[k]);
		}
		
		if(flag_N2==0)	printf("No account is modified.\n");
	}
	return 0;
}
