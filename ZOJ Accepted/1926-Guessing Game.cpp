#include<cstdio>
using namespace std;
int main()
{
	int tmp,max=11,min=0,key;
	char word[8];
	while(scanf("%d",&tmp)!=EOF&&tmp!=0){
		scanf("%s%s",word,word);
		if(word[0]=='h'&&tmp<max)	max=tmp;
		else if(word[0]=='l'&&tmp>min)	min=tmp;
		else if(word[0]=='o'){
			key=tmp;
			if(key>min&&key<max){
				printf("Stan may be honest\n");
				max=11;
				min=0;
			}
			else{
				printf("Stan is dishonest\n");
				max=11;
				min=0;
			}
		}
	}
	return 0;
}
