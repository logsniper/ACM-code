#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int comp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}

int main()
{
	int n=0,i,j;
	char num[9][11];
	while(scanf("%s",num[0])!=EOF){
		bool flag=1;
		n++;i=0;
		do{
			i++;
			scanf("%s",num[i]);
		}while(num[i][0]!='9');
		int set=i;
		qsort(num,set,sizeof(num[0]),comp);
		for(i=0;i<set-1;i++){
			int len=strlen(num[i]);
			int equal_num=0;
			for(j=0;j<len;j++)
				if(num[i][j]==num[i+1][j])	equal_num++;
			if(equal_num==len)	{flag=0;break;}
		}
		if(flag) printf("Set %d is immediately decodable\n",n);
		else printf("Set %d is not immediately decodable\n",n);
	}
	return 0;
}
