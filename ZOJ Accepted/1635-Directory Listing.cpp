//zoj 1635

#include <cstdio>
#include <cstring>
struct Node{
	char name[16];
	int size;
	int level;
	int father;
};
class Tree {
private:
	struct Node tnode[100];
	int nodenum;
	inline int str2int(char str[],int l,int r)
	{
		int ret=0;
		for(int i=l;i<=r;++i){
			ret*=10;
			ret+=str[i]-'0';
		}
		return ret;
	}
	inline void getname(char str[],int l,int r,char name[])
	{
		int i;
		for(i=0;i<=r-l;++i)
			name[i]=str[l+i];
		name [i]='\0';
	}
	inline void arrangeTree(char str[],int l,int r,int level,int k)
	{
		if(l>r)	return;
		int father=0,count;
		while(father<nodenum&&tnode[father].level<level-1)	++father;
		for(count=0;count<k&&father<nodenum;++father){
			if(tnode[father].name[0]=='*')	++count;
			if(count==k)	break;
		}
		for(int i=l;i<=r;++i){
			while(str[i]==' ')	++i;
			if(i>r)	break;
			l=i;
			while(str[i]!=' ')	++i;
			if(i>r)	break;
			getname(str,l,i-1,tnode[nodenum].name);
			while(str[i]==' ')	++i;
			l=i;
			while(str[i]!=' '&&i<=r){
				++i;
			}
			tnode[nodenum].size=str2int(str,l,i-1);
			tnode[nodenum].level=level;
			tnode[nodenum].father=father;
			++nodenum;
		}
	}
public:
	char line[1000];
	inline bool input()
	{
		if(scanf("%s%d",&tnode[0].name,&tnode[0].size)==EOF)
			return false;
		tnode[0].level=0,tnode[0].father=-1;
		nodenum=1;
		int level=1;
		getchar();
		while(1){
			bool finish=true;
			gets(line);
			int len=strlen(line);
			int k=0;
			for(int i=0;i<len;++i){
				int l,r;
				while(line[i]!='(')	++i;
				l=i+1;
				while(line[i]!=')')	++i;
				r=i-1;
				++k;
				arrangeTree(line,l,r,level,k);
			}
			++level;
			for(int i=0;i<len;++i)
				if(line[i]=='*'){
					finish=false;
					break;
				}
			if(finish)	return true;
		}
	}
	inline void output()
	{
		char opmatrix[100][100];
		bool visited[100];
		for(int i=nodenum-1;i>=0;--i)
			tnode[tnode[i].father].size+=tnode[i].size;
		for(int i=0;i<100;++i){
			visited[i]=false;
			for(int j=0;j<100;++j)
				opmatrix[i][j]=' ';
		}
		sprintf(opmatrix[0],"|_%s[%d]",tnode[0].name,tnode[0].size);
		visited[0]=true;
		int next=1,linenum;
		for(linenum=1;linenum<nodenum;++linenum){
			char tmp[20];
			sprintf(tmp,"|_%s[%d]",tnode[next].name,tnode[next].size);
			int s=8*tnode[next].level;
			for(int j=0;j<=strlen(tmp);++j)
				opmatrix[linenum][s+j]=tmp[j];
			visited[next]=true;
			bool noson=true;
			for(int j=next+1;j<nodenum;++j)
				if(tnode[j].father==next){
					next=j;
					noson=false;
					break;
				}
			if(noson){
				while(next&&tnode[next].father!=tnode[next+1].father){
					next=tnode[next].father;
				}
				++next;
			}
		}
		for(int j=0;j<100;j+=8){
			for(int i=nodenum-1;i>=0;--i){
				if(opmatrix[i][j]=='|'){
					while(i>0&&opmatrix[i-1][j]==' '){
						opmatrix[i-1][j]='|';
						--i;
					}
				}
			}
		}
		for(int i=0;i<nodenum;++i)
			printf("%s\n",opmatrix[i]);
	}
};
int main()
{
//	freopen("input.txt","r",stdin);
	class Tree dir;
	while(dir.input())
		dir.output();
	return 0;
}