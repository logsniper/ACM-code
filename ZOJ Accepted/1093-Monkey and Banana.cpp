#include<cstdio>
#include<cstdlib>
typedef struct BOX{
	int x,y,z;
}BOX;
BOX box[180];
int ans[180],boxnum;

int dp(int k)
{
	if(ans[k]>=0)	return ans[k];
	int max=0;
	for(int i=0;i<boxnum;++i){
		if(box[i].x>box[k].x&&box[i].y>box[k].y&&dp(i)>max)
			max=dp(i);
	}
	ans[k]=max+box[k].z;
	return ans[k];
}

bool init()
{
	int x,y,z;
	int n;
	scanf("%d",&n);
	if(n==0)	return false;
	int i;
	boxnum=0;
	for(i=0;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		box[boxnum].x=x,box[boxnum].y=y,box[boxnum].z=z;
		++boxnum;
		if(x!=y){
			box[boxnum].x=y,box[boxnum].y=x,box[boxnum].z=z;
			++boxnum;
		}
		if(x!=z){
			box[boxnum].x=z,box[boxnum].y=y,box[boxnum].z=x;
			++boxnum;
			if(z!=y){
				box[boxnum].x=y,box[boxnum].y=z,box[boxnum].z=x;
				++boxnum;			
			}
		}
		if(y!=z){
			box[boxnum].x=x,box[boxnum].y=z,box[boxnum].z=y;
			++boxnum;
			if(x!=z){
				box[boxnum].x=z,box[boxnum].y=x,box[boxnum].z=y;
				++boxnum;
			}
		}
	}
	for(i=0;i<boxnum;i++)
		ans[i]=-1;
}

int main()
{
	int cas=0;
	while(init()){
		cas++;
		int k,max=0;
		for(k=0;k<boxnum;k++)
			if(dp(k)>max)	max=dp(k);
		printf("Case %d: maximum height = %d\n",cas,max);
	}
	return 0;
}
