#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(char*)b-*(char*)a;
}
int main()
{
	int target,n;
	int v,w,x,y,z;
	int tmp1,tmp2,tmp3,tmp4,tmp5;
	char letter[16];
	bool used[16];
	while(scanf("%d%s",&target,letter)&&(target!=0||strcmp(letter,"END")!=0)){
		n=strlen(letter);
		for(tmp5=0;tmp5<n;tmp5++)
			used[tmp5]=0;
		qsort(letter,n,1,comp);
		for(tmp1=0;tmp1<n;tmp1++){
			used[tmp1]=1;
			v=letter[tmp1]-'A'+1;
			for(tmp2=0;tmp2<n;tmp2++){
				if(used[tmp2]==1)	continue;
				used[tmp2]=1;
				w=letter[tmp2]-'A'+1;
				w=w*w;
				for(tmp3=0;tmp3<n;tmp3++){
					if(used[tmp3]==1)	continue;
					used[tmp3]=1;
					x=letter[tmp3]-'A'+1;
					x=x*x*x;
					for(tmp4=0;tmp4<n;tmp4++){
						if(used[tmp4]==1)	continue;
						used[tmp4]=1;
						y=letter[tmp4]-'A'+1;
						y=y*y*y*y;
						for(tmp5=0;tmp5<n;tmp5++){
							if(used[tmp5]==1)	continue;
							z=letter[tmp5]-'A'+1;
							z=z*z*z*z*z;
							if(target==v-w+x-y+z){
								printf("%c%c%c%c%c\n",letter[tmp1],letter[tmp2],letter[tmp3],letter[tmp4],letter[tmp5]);
								goto OUT;
							}
						}
						used[tmp4]=0;
					}
					used[tmp3]=0;
				}
				used[tmp2]=0;
			}			
			used[tmp1]=0;
		}
OUT :	if(target!=v-w+x-y+z)
			printf("no solution\n");
	}
	return 0;
}
