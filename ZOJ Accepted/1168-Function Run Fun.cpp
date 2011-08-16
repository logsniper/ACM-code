#include<iostream>
using namespace std;
#define MAX 51
long long fuck[21][21][21];
long long w(int a,int b,int c)
{
	long long sum=0,tmp;
	if(a<=0||b<=0||c<=0)	return 1;
	if(a>20||b>20||c>20){		
		if(fuck[20][20][20]==0){
			fuck[20][20][20]=w(20,20,20);
		}
		tmp=fuck[20][20][20];
		sum+=tmp; 
		return tmp;
	}
	if(a < b && b < c){
		if(fuck[a][b][c-1]==0){
			fuck[a][b][c-1]=w(a, b, c-1);
		}
		tmp=fuck[a][b][c-1];
		sum+=tmp;
		
		if(fuck[a][b-1][c-1]==0){
			fuck[a][b-1][c-1]=w(a, b-1, c-1);
		}
		tmp=fuck[a][b-1][c-1];
		sum+=tmp;
		
		if(fuck[a][b-1][c]==0){
			fuck[a][b-1][c]=w(a, b-1, c);
		}
		tmp=fuck[a][b-1][c];
		sum-=tmp;
		
		return sum;
	}
	else{
		if(fuck[a-1][b][c-1]==0){
			fuck[a-1][b][c-1]=w(a-1, b, c-1);
		}
		tmp=fuck[a-1][b][c-1];
		sum+=tmp;
		
		if(fuck[a-1][b-1][c]==0){
			fuck[a-1][b-1][c]=w(a-1, b-1, c);
		}
		tmp=fuck[a-1][b-1][c];
		sum+=tmp;
		
		if(fuck[a-1][b][c]==0){
			fuck[a-1][b][c]=w(a-1, b, c);
		}
		tmp=fuck[a-1][b][c];
		sum+=tmp;		
		
		if(fuck[a-1][b-1][c-1]==0){
			fuck[a-1][b-1][c-1]=w(a-1, b-1, c-1);
		}
		tmp=fuck[a-1][b-1][c-1];
		sum-=tmp;
		
		return sum;	
	}
}
int main()
{
	int a,b,c;
	long long ans;
	for(a=0;a<21;a++)
		for(b=0;b<21;b++)
			for(c=0;c<21;c++)
				fuck[a][b][c]=0;
	fuck[0][0][0]=1;
	fuck[20][20][20]=w(20,20,20);
	while(cin>>a>>b>>c&&(a!=-1||b!=-1||c!=-1)){
		if(a<=0||b<=0||c<=0||a>20||b>20||c>20){
			ans=w(a,b,c);
		}
		else{
			if(fuck[a][b][c]==0){
				fuck[a][b][c]=w(a,b,c);
			}
			ans=fuck[a][b][c];
		}
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
	}
	return 0;
}
