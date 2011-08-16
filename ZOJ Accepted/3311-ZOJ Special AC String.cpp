#include <cstdio>
#include <cstring>
int zpos,jpos;
char str[104];
bool check()
{
	int znum=0,jnum=0;
	int len=strlen(str);
	bool o=false;
	for(int i=0;i<len;++i){
		if(str[i]=='Z'){
			zpos=i;znum++;
		}
		else if(str[i]=='J'){
			jpos=i;jnum++;
		}
		else if(str[i]=='O')	o=true;
		else	return false;
	}
	if(o&&znum==1&&jnum==1&&zpos+1<jpos)	return true;
	else return false;
}

int main()
{
	while(scanf("%s",str)!=EOF){
		if(!check())	printf("Wrong Answer\n");
		else{
			int an=zpos,bn=jpos-zpos-1,cn=strlen(str)-jpos-1;
			while(bn>1){--bn;--cn;}
			if(an==cn-1)	printf("Accepted\n");
			else	printf("Wrong Answer\n");
		}
	}
	return 0;
}