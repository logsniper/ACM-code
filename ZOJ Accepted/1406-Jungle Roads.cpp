#include<cstdio>
#include<iostream>
using namespace std;
int route[30][30];
int prim(int P)
{
	int total=0;
	int i,j;
	int closest[30],nearest_target=0;
	int length_min;
	bool s[30];
	for(i=2;i<=P;i++)
		s[i]=false;
	s[1]=true;
	for(i=2;i<=P;i++){
		if(route[1][i]!=0){
			closest[i]=1;
			if(route[1][i]<route[1][nearest_target])
				nearest_target=i;
		}
		else closest[i]=0;
	}
	total+=route[nearest_target][closest[nearest_target]];
	for(i=2;i<P;i++){
		s[nearest_target]=true;
		for(j=2;j<=P;j++){
			if(s[j])	continue;
			if(route[j][nearest_target]!=0&&route[j][nearest_target]<route[j][closest[j]])
				closest[j]=nearest_target;
		}
		nearest_target=0;
		length_min=route[0][0];
		for(j=2;j<=P;j++){
			if(s[j])	continue;
			if(route[j][closest[j]]<length_min){
				length_min=route[j][closest[j]];
				nearest_target=j;
			}
		}
		total+=route[nearest_target][closest[nearest_target]];
//	printf("%d ",total);
	}
	return total;
}
int main()
{
	int N;
	char from_tmp[2],to_tmp[30][2];
	int a,b;
	int from_num,length_tmp;
	int i,j;
	int result;
	for(i=0;i<27;i++){
		route[i][0]=99999999;
		route[0][i]=99999999;
	}
	while(scanf("%d",&N)&&N!=0){
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				route[i][j]=0;
		for(i=0;i<N-1;i++){
			scanf("%s%d",from_tmp,&from_num);
			a=from_tmp[0]-'A'+1;
			for(j=0;j<from_num;j++){
				scanf("%s%d",to_tmp[j],&length_tmp);
				b=to_tmp[j][0]-'A'+1;
				route[a][b]=length_tmp;
				route[b][a]=length_tmp;
			}
		}
//		printf(" ");
		result=prim(N);
		printf("%d\n",result);
	}
	return 0;
}
