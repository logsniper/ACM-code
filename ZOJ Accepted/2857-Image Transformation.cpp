#include<iostream>
using namespace std;
int main()
{
	int rgb[3][100][100];
	int sum,gray[100][100];
	int N,M;
	int i,j,k;
	int number=0;
	while(cin>>N>>M&&N!=0&&M!=0){
		number++;
		for(k=0;k<3;k++)
			for(i=0;i<N;i++)
				for(j=0;j<M;j++)
					cin>>rgb[k][i][j];
		for(i=0;i<N;i++)
			for(j=0;j<M;j++){
				sum=0;
				for(k=0;k<3;k++)
					sum+=rgb[k][i][j];
				gray[i][j]=sum/3;
			}
		cout<<"Case "<<number<<":"<<endl;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				cout<<gray[i][j];
				if(j!=M-1)	cout<<",";
			}
			cout<<endl;
		}
	}
	return 0;
}
