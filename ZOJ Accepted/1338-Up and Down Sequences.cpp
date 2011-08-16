#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int seq[31],tmp;
	int n,i;
	double up_num,down_num,tmp_num;
	int up_time,down_time;
	char now_state;
	bool flag;
	while(cin>>tmp&&tmp!=0){
		seq[0]=tmp;
		for(i=1;cin>>seq[i];i++)
			if(seq[i]==0)	break;
		n=i-1;
		up_num=0; down_num=0; tmp_num=0; up_time=0; down_time=0;
		now_state='0';flag=0;
		for(i=1;i<=n;i++){
			if(seq[i]>seq[i-1]){
				if(flag==0)	up_num+=tmp_num;
				if(now_state!='u'){
					up_time++;
					now_state='u';
				}
				up_num++;
				if(!flag)	flag=1;
			}
			else if(seq[i]<seq[i-1]){
				if(flag==0)	down_num+=tmp_num;
				if(now_state!='d'){
					down_time++;
					now_state='d';
				}
				down_num++;
				if(!flag)	flag=1;
			}
			else{
				if(flag==0)	tmp_num++;
				else if(now_state=='u')	up_num++;
				else if(now_state=='d')	down_num++;
			}
		}
		if(up_time)	up_num=double(up_num/up_time);
		if(down_time)	down_num=double(down_num/down_time);
		printf("Nr values = %d:  %.6lf %.6lf\n",n+1,up_num,down_num);
	}
	return 0;
}
