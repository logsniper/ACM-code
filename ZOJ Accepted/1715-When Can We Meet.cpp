#include<iostream>
using namespace std;
int main()
{
	int date[50][101];
	int N,Q;
	while(cin>>N>>Q&&!(N==0&&Q==0)){
		int committee,i;
		int date_q[101],date_most=0,date_fit=0;
		for(i=0;i<101;i++)	date_q[i]=0;
		for(committee=0;committee<N;committee++){
			cin>>date[committee][0];
			for(i=1;i<=date[committee][0];i++){
				cin>>date[committee][i];
				int tmp=date[committee][i];
				date_q[tmp]++;
			}
		}
		for(i=1;i<=100;i++)
			if(date_q[i]>=Q&&(date_q[i]>date_most)){
				date_most=date_q[i];
				date_fit=i;
			}
		cout<<date_fit<<endl;
	}
	return 0;
}
