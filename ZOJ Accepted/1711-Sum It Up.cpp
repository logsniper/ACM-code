#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int seq[12],k;
vector <string> history;
bool dfs(int num[],int n,int tgt,int depth,int nowsum)
{
	if(depth==n){
		if(tgt==nowsum){
			string sum="";
			char tmp[8];
			for(int i=0;i<k;++i){
				if(i)
					sum+='+';
				sprintf(tmp,"%d",seq[i]);
				sum+=tmp;
			}
			bool appear=false;
			for(int i=0;i<history.size();++i)
				if(sum==history[i])
					appear=true;
			if(!appear)
				history.push_back(sum);
			return true;
		}
		return false;
	}
	seq[k]=num[depth];
	++k;
	bool key1=dfs(num,n,tgt,depth+1,nowsum+num[depth]);
	--k;
	bool key2=dfs(num,n,tgt,depth+1,nowsum);
	return key1||key2;
}

int main()
{
	int t,n;
	int num[12];
	while(cin>>t>>n&&n>0){
		for(int i=0;i<n;++i)
			cin>>num[i];
		qsort(num,n,sizeof(int),comp);
		k=0;
		history.clear();
		cout<<"Sums of "<<t<<":"<<endl;
		bool res = dfs(num,n,t,0,0);
		if(!res)
			cout<<"NONE"<<endl;
		else{
			for(int i=0;i<history.size();++i)
				cout<<history[i]<<endl;
		}
	}
	return 0;
}
