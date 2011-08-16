#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct DNA{
	int inver;
	char fuck[51];
}dna;

int compare(const void *a,const void *b)
{
	return ((dna*)a)->inver-((dna*)b)->inver;
}
//¡¡¡¡qsort(strin,total,sizeof(str),compare);
int main()
{
	int N,n,m;
	dna shit[100];
	int k,i,j,length;
	scanf("%d",&N);
	while(N--){
		scanf("%d%d",&n,&m);
		for(k=0;k<m;k++){
			scanf("%s",shit[k].fuck);
			length=strlen(shit[k].fuck);
			shit[k].inver=0;
			for(i=0;i<length;i++)
				for(j=i+1;j<length;j++)
					if(shit[k].fuck[i]>shit[k].fuck[j])	shit[k].inver++;
		}
		qsort(shit,m,sizeof(dna),compare);
		for(j=0;j<m;j++)
			printf("%s\n",shit[j].fuck);
		if(N)	printf("\n");
	}
	return 0;
}
