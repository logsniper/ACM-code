#include<iostream>
using namespace std;

typedef struct stu{
	int candy;
	stu *next,*last;
}STU;

bool check(STU* fixed)
{
	STU *prev=fixed,*now=prev->next;
	do{
		if(prev->candy!=now->candy)
			return 0;
		prev=now;
		now=now->next;
	}while(prev!=fixed);
	return 1;
}

int main()
{
	int N,steps;
	STU *fixed,*now,*prev;
	while(cin>>N&&N!=0){
		int i;
		fixed=new(STU),now=fixed,prev=fixed;
		cin>>fixed->candy;
		for(i=1;i<N;i++){
			now=new(STU);
			prev->next=now;
			now->last=prev;
			cin>>now->candy;
			prev=now;
		}
		now->next=fixed;
		fixed->last=now;
		
/*		now=fixed;
		do{
			cout<<now->candy<<" ";
			now=now->next;
		}while(now!=fixed);*/
		
		steps=0;
		while(!check(fixed)){
			now=fixed;
			do{
				now->candy/=2;
//				cout<<now->candy<<" ";
				prev=now;
				now=now->next;
			}while(now!=fixed);

			int tmp=fixed->candy;
			now=fixed;
			prev=now->last;
			do{
				now->candy+=prev->candy;
				prev=prev->last;
				now=now->last;
			}while(now->last!=fixed);
			now->candy+=tmp;

			now=fixed;
			prev=now->last;
			do{
				if(now->candy%2)	now->candy++;
				prev=now;
				now=now->next;
			}while(now!=fixed);
//			cout<<endl;
			steps++;
		}
		cout<<steps<<" "<<fixed->candy<<endl;
		while(N--){
			prev=now->next;
			delete(now);
			now=prev;
		}
	}
	return 0;
}
