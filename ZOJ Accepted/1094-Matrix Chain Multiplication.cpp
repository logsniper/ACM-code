#include <cstdio>
#include <cstring>
typedef class Matrix{
public:
	char name[4];
	int row,col;
	int multnum;
	const void operator =(const Matrix b)
	{
		strcpy(name,b.name);
		row=b.row,col=b.col;
		multnum=b.multnum;
	}
	bool mult(const Matrix b)
	{
		if(col!=b.row)	return false;
		strcpy(name,b.name);
		multnum=multnum+b.multnum+row*col*b.col;
//		printf("mult more : %d, now : %d\n",row*col*b.col,multnum);
		col=b.col;
		return true;
	}
}Matrix;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	Matrix mtr[26];
	Matrix stack[200];
	Matrix kuo;
	char command[400];
	bool err;
	int top=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s%d%d",mtr[i].name,&mtr[i].row,&mtr[i].col);
		mtr[i].multnum=0;
	}
	strcpy(kuo.name,"(");
	kuo.row=0,kuo.col=0,kuo.multnum=0;
	while(scanf("%s",command)!=EOF){
		int len=strlen(command);
		top=-1;
		err=false;
		for(int i=0;i<len;++i){
			if(command[i]=='('){
				++top;
				stack[top]=kuo;
			}
			else if(command[i]!=')'){
				++top;
				int j;
				for(j=0;j<26&&mtr[j].name[0]!=command[i];++j);
				stack[top]=mtr[j];
			}
			else{
				--top;
				err=!(stack[top].mult(stack[top+1]));
				if(err){
					break;
				}
				--top;
				stack[top]=stack[top+1];
			}
		}
		if(err||top!=0)
			printf("error\n");
		else
			printf("%d\n",stack[0].multnum);
	}
	return 0;
}