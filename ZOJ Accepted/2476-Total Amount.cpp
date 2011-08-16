#include<cstdio>
#include<cstdlib>
#include<cstring>
int main()
{
	char input[16],result[16],num[12];
	int total;
	int N;
	while(scanf("%d",&N)&&N>0){
		int i,j;
		int t;
		total=0;
		for(i=0;i<N;i++){
			scanf("%s",input);
			int tmp=0;
			for(j=0;input[j]!='\0';j++){
				if(input[j]>='0'&&input[j]<='9')
					tmp=tmp*10+input[j]-'0';
			}
			total+=tmp;
//			printf("%lf\n",tmp);
		}
		
//		char str[256];
//		sprintf(str, "%.0lf", total);
//		t = atoi(str);
//		printf("%lf %d\n",total,t);
		t=total;
		for(i=0;t>0;t/=10,i++)
			num[i]=t%10+'0';
		while(i<3){
			num[i++]='0';
		}
		num[i]='\0';
		for(i=0,j=0;num[i]!='\0';i++){
			if(i==2){
				result[j++]='.',result[j++]=num[i];
				continue;
			}
			else if(i%3==2){
				result[j++]=',',result[j++]=num[i];
				continue;
			}
			else result[j++]=num[i];
		}
		result[j]='$';
		for(i=j;i>=0;i--)
			printf("%c",result[i]);
		printf("\n");
	}
	return 0;
}
