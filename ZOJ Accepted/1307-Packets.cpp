#include<cstdio>
int cal(int num[])
{
	if(num[0]+num[1]+num[2]+num[3]+num[4]+num[5]==0)
		return -1;
	
	int ret=num[5];
	
	ret+=num[4];
	num[0]-=num[4]*11;
	
	ret+=num[3];
	if(num[1]>=num[3]*5)	num[1]-=num[3]*5;
	else{
		num[0]-=num[3]*5-num[1];
		num[1]=0;
	}
	
	if(num[2]%4==0)
		ret+=num[2]/4;
	else{
		ret+=num[2]/4+1;
		if(num[2]%4==1){
			if(num[1]>=5){
				num[1]-=5;
				num[0]-=7;
			}
			else{
				num[0]-=27-num[1]*4;
				num[1]=0;
			}
		}
		else if(num[2]%4==2){
			if(num[1]>=3){
				num[1]-=3;
				num[0]-=6;
			}
			else{
				num[0]-=18-num[1]*4;
				num[1]=0;
			}
		}
		else if(num[2]%4==3){
			if(num[1]>=1){
				--num[1];
				num[0]-=5;
			}
			else{
				num[0]-=9;
			}
		}
	}
	
	if(num[1]%9==0)
		ret+=num[1]/9;
	else{
		ret+=num[1]/9+1;
		num[0]-=(9-num[1]%9)*4;
	}

	if(num[0]>0){
		if(num[0]%36==0)
			ret+=num[0]/36;
		else
			ret+=num[0]/36+1;
	}
	
	return ret;
}

int main()
{
	int num[6];
	while(1){
		for(int i=0;i<6;++i)
			scanf("%d",&num[i]);
		int ans=cal(num);
		if(ans==-1)	break;
		else
			printf("%d\n",ans);
	}
	return 0;
}
