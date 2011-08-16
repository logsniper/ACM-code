#include<iostream>
#include<cstdio>
using namespace std;

typedef struct step_stack{
	int this_path;
	int all_path;
	int high;
	step_stack *down;
}Step;

int main()
{
	long x,y;
	long L;
	Step *bottom,*top;
	Step *next,*tmp;
	while(scanf("%ld%ld",&x,&y)!=EOF){
		L=y-x;
		//initialize
		bottom=new(Step);
		bottom->this_path=1;
		bottom->all_path=1;
		bottom->high=1;
		bottom->down=NULL;
		top=bottom;

		while(top->all_path<=L){
			next=new(Step);
			next->this_path=top->this_path+1;
			next->all_path=top->all_path+next->this_path;
			next->high=top->high+1;
			next->down=top;
			top=next;
		}
		
		while(top->all_path!=L||top->this_path!=1){
			while(top->all_path<L){
				next=new(Step);
				next->this_path=top->this_path+1;
				next->all_path=top->all_path+next->this_path;
				next->high=top->high+1;
				next->down=top;
				top=next;
			}
			if(top->this_path>=top->down->this_path){
				top->this_path--;
				top->all_path--;
			}
			else{
				do{
					tmp=top;
					top=top->down;
					delete(tmp);
				}while(top->this_path<top->down->this_path);
				top->this_path--;
				top->all_path--;
			}
		}
		printf("%d\n",top->high);
	}
	return 0;
}
