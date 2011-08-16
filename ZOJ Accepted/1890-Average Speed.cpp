#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int char2int(char num[])
{
	int len=strlen(num),ret=0;
	for(int i=0;i<len;++i){
		if(i)	ret*=10;
		ret+=num[i]-'0';
	}
//	printf("%d ",ret);
	return ret;
}

int elapse(char time[])
{
	char h[3],m[3],s[3];
	h[0]=time[0],h[1]=time[1],h[2]='\0';
	m[0]=time[3],m[1]=time[4],m[2]='\0';
	s[0]=time[6],s[1]=time[7],s[2]='\0';
	return char2int(h)*3600+char2int(m)*60+char2int(s);
}

int main()
{
	char orders[20];
/*	while(scanf("%s",orders)){
		printf("%d\n",char2int(orders));
	}*/
	double state_dist=0.0f;
	int state_elapse=0,state_speed=0,i,j;
	while(cin.getline(orders,20)){
		int len=strlen(orders);
		char time[10];
		for(i=0;i<8;++i)
			time[i]=orders[i];
		time[i]='\0';
		int nowtime=elapse(time);
		if(len > 9){
			state_dist+=(nowtime-state_elapse)*1.0f*state_speed/3600.0;
			state_elapse=nowtime;
			char num[8];
//			printf("%d ",nowtime);
			for(i=8;orders[i]<'0'||orders[i]>'9';++i);
			for(j=0;orders[i+j]>='0'&&orders[i+j]<='9';++j)
				num[j]=orders[i+j];
			num[j]='\0';
			state_speed=char2int(num);
		}
		else{
			double dist=state_dist;
			dist+=(nowtime-state_elapse)*1.0f*state_speed/3600.0;
			printf("%s %.2lf km\n",time,dist);
		}
	}
	return 0;
}
