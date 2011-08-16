#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct dict
{
	char eng[11];
	char fml[11];
}dict;
int comp(const void *a,const void *b)
{
	return strcmp( ((dict*)a)->fml,((dict*)b)->fml );
}
int main(){
	dict FtoE[100005];
	char word[22],tmp;
	int n=0,i,flag,flag1,len_eng,len_fml;
	int first,mid,last;
	flag=1;
	while(flag){
		flag=0;i=0;
		len_fml=0;len_eng=0;
		while(1){
			tmp=getchar();
			if(tmp==' '){
				flag=1;
				break;
			}
			else if(tmp=='\n') break;
			else{
				word[i++]=tmp;
			}
		}
		word[i]='\0';
		if(flag){
			strcpy(FtoE[n].eng,word);
			scanf("%s",FtoE[n].fml);
//			printf("%s %s %s %d\n",word,FtoE[n].eng,FtoE[n].fml,n);
			n++;
			getchar();
		}
	}
	qsort(FtoE,n,sizeof(dict),comp);
//	for(i=0;i<n;i++)
//		printf(" %s %s %d\n",FtoE[i].eng,FtoE[i].fml,i);
	while(scanf("%s",word)!=EOF){
		first=0;last=n-1;
		while(1){
			mid=(int)(first+last)/2;
			flag=strcmp(FtoE[mid].fml,word);
			flag1=strcmp(FtoE[mid+1].fml,word);
			if(first==mid&&flag!=0){
				printf("eh\n");
				break;
			}
			if(flag1==0){
				printf("%s\n",FtoE[mid+1].eng);
				break;
			}
			if(flag==0){
				printf("%s\n",FtoE[mid].eng);
				break;
			}
			else if(flag<0)	first=mid;
			else if(flag>0) last=mid;
		}
	}
	return 0;
}
