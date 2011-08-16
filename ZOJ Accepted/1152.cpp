#include<iostream>
//#include<math.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n,m;
		int count=0;
		cin>>n>>m;
		for(int j=1;n!=0||m!=0;count=0,j++){
			for(int a=1;a<n;a++)
				for(int b=a+1;b<n;b++){
					int s=a*a+b*b+m;
					int t=a*b;
					float p=(float)s/t;
					int q=s/t;
					if(p==q) count++;
				}
			cout<<"Case "<<j<<": "<<count<<endl;
			cin>>n>>m;
		}
		if(i!=N-1) cout<<endl;
	}
	return 0;
}
