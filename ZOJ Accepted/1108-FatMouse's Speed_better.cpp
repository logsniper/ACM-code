#include<cstdio>
#include<iostream>
#include<cstdlib>
#define UP_LIMITE 2147483647
using namespace std;
typedef struct mice{
	int weight;
	int speed;
	int number;
}mice;
int comp(const void* a,const void * b)
{
	int k;
	k=((mice*)a)->weight-((mice*)b)->weight;
	if(k==0)	k=((mice*)b)->speed-((mice*)a)->speed;
	return k;
}


typedef struct ans{
	int num;
	int total_num;
}ans;
int s[1001][3];
ans solute(mice a[],int n,int k){
	int i,flag;
	ans max,tmp;
	max.total_num=0;
	for(i=k+1;i<n;i++){
		if(a[i].speed<a[k].speed&&a[i].weight!=a[k].weight){
			if(s[i][0]==1)	tmp.total_num=s[i][2]+1;
			else tmp.total_num=solute(a,n,i).total_num+1;
			if(max.total_num<tmp.total_num){
				flag=i;
				max.total_num=tmp.total_num;
			}
		}
	}
	max.num=flag;
	s[k][1]=max.num;
	s[k][2]=max.total_num;
	s[k][0]=1;
	return max;
}


int main()
{
	mice  m[1001];
	int i,j,k,t,n;
	ans max,tmp;
	for(i=0;i<1001;i++){
		s[i][0]=0;
		s[i][1]=0;s[i][2]=0;
	}
	m[0].weight=0;m[0].speed=UP_LIMITE;m[0].number=0;
	for(n=1;(scanf("%d%d",&m[n].weight,&m[n].speed)!=EOF)&&m[n].weight!=0;n++){
//	for(n=1;scanf("%d%d",&m[n].weight,&m[n].speed);n++){	
		m[n].number=n;
	}
	qsort(m,n,sizeof(mice),comp);
	max=solute(m,n,0);
	cout<<max.total_num<<endl;
	tmp=max;
	do{
		cout<<m[tmp.num].number<<endl;
		tmp=solute(m,n,tmp.num);
	}while(tmp.total_num>0);
	return 0;
}
