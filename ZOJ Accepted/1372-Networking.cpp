#include<iostream>
using namespace std;
int route[51][51];
int prim(int P)
{
	int total=0;
	int i,j;
	int closest[51],nearest_target=0;
	bool s[51];
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
//	cout<<nearest_target<<" ";
	for(i=2;i<=P;i++){
//		cout<<i<<" ";
		s[nearest_target]=true;
		for(j=2;j<=P;j++){
			if(s[j])	continue;
			if(route[j][nearest_target]!=0&&route[j][nearest_target]<route[j][closest[j]])
				closest[j]=nearest_target;
		}
		nearest_target=0;
		int length_min=route[0][0];
		for(j=2;j<=P;j++){
			if(s[j])	continue;
			if(route[j][closest[j]]<length_min){
				length_min=route[j][closest[j]];
				nearest_target=j;
			}
		}
		total+=route[nearest_target][closest[nearest_target]];
	}
	return total;
}
int main()
{
	int P,R;
	int from_tmp,to_tmp,length_tmp;
	int i,j;
	int result;
	for(i=0;i<51;i++){
		route[i][0]=99999999;
		route[0][i]=99999999;
	}
	while(cin>>P&&P!=0){
		cin>>R;
		for(i=1;i<=P;i++)
			for(j=1;j<=P;j++)
				route[i][j]=0;
		for(i=0;i<R;i++){
			cin>>from_tmp>>to_tmp>>length_tmp;
			if(route[from_tmp][to_tmp]!=0&&length_tmp>=route[from_tmp][to_tmp])	continue;
			route[from_tmp][to_tmp]=length_tmp;
			route[to_tmp][from_tmp]=length_tmp;
//			cout<<route[to_tmp][from_tmp]<<" ";
		}
		result=prim(P);
		cout<<result<<endl;
	}
	return 0;
}
