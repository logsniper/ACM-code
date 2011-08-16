#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct equal{
	char left[10];
	char right[10];
}equal;
int comp(const void *a,const void *b)
{
	return strcmp((char *) a,(char *) b);
}
int main()
{
	equal now;
	int N,n,k,i,j,init_num,flag_left,flag_right,flag_num;
	char initialized[1000][10],tmp;
	init_num=1;n=1;
	while(scanf("%d",&N)&&N!=0){
		initialized[0][0]='a';initialized[0][1]='\0';
		for(i=1;i<1000;i++){
			initialized[i][0]='0';initialized[i][1]='\0';
		}
		getchar();
		while(N--){
			flag_left=0;flag_right=0;
			for(k=0;scanf("%c",now.left+k)&&now.left[k]>='a'&&now.left[k]<='z';k++);
			now.left[k]='\0';
			while(scanf("%c",&tmp)&&(tmp<'a'||tmp>'z'));
			now.right[0]=tmp;
			for(k=1;scanf("%c",now.right+k)&&now.right[k]!='\n';k++);
			now.right[k]='\0';
//			printf("%s %s\n",now.left,now.right);
			for(i=0;i<init_num;i++){
				if(strcmp(initialized[i],now.right)==0){
					for(j=0;j<init_num;j++){
						if(strcmp(initialized[j],now.left)==0){
							flag_right=1;
							break;
						}
					}
					if(flag_right==0)
						strcpy(initialized[init_num++],now.left);
				}
				if(strcmp(initialized[i],now.left)==0){
					for(j=0;j<init_num;j++){
						if(strcmp(initialized[j],now.right)==0){
							flag_left=1;
							break;
						}
					}
					if(flag_left==0){
						initialized[i][0]='0';
						initialized[i][1]='\0';
					}
				}
			}
		}
		flag_num=0;
		qsort(initialized,init_num,sizeof(char)*10,comp);
		printf("Program #%d\n",n);
		for(i=0;i<=init_num;i++){
			if(initialized[i][0]>='a'&&initialized[i][0]<='z'
				&&strcmp(initialized[i],initialized[i-1])!=0){
			
				printf("%s ",initialized[i]);
				flag_num=1;
			}
		}
		if(flag_num==0) printf("none");
		printf("\n\n");
		n++;
	}
	return 0;
}
