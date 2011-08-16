#include<cstdio>
using namespace std;
int find1(int amount)
{
	int left=amount,first=1,step=1,now=1;
	bool del=0;
	while(left>1){
		if(del){
			left--;
		}
		int tmp=now+step-amount;
		if(tmp<=0){
			now=now+step;
		}
		else{
			step*=2;
			now=first;
			if(!del){
				first=first+step;
			}
		}
		del=!del;
	}
	return first;
}
int find2(int amount){
	int left=amount,first=1,step=2,now=1;
	while(left>1){
		if(now+step<=amount)	now+=step;
		else{
			if(now+step/2<=amount){
				now=first;
				step*=2;
			}
			else{
				first=first+step;
				step*=2;
				now=first;
			}
		}
		left--;
	}
	return first;
}
int main()
{
	int x,y,z;
	FILE* fw;
	fw=fopen("2239_table.txt","w");
	for(z=0;z<=6;z++){
		for(x=0;x<=9;x++){
			for(y=0;y<=9;y++){
				if(x==0&&y==0){
					fprintf(fw,"0,");
					continue;
				}
				int amount=x*10+y;
				int i=z;
				while(i--)	amount*=10;
				int key=find2(amount);
				fprintf(fw,"%d,",key);
			}
		}
		fprintf(fw,"\n");
	}
	return 0;
}
