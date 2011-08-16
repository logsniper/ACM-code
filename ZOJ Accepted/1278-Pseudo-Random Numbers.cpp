#include<iostream>
using namespace std;
int main()
{
	int Z,I,M,L;
	int n,L0,ans;
	n=0;
	while(cin>>Z>>I>>M>>L){
		n++;
		if(Z==0&&I==0&&M==0&&L==0)	break;
		L0=L;ans=0;
		Z=Z%M;I=I%M;
		do{
			if(ans>M){
				L0++;
				L=L0;
				ans=0;
			}
			L=(Z*L+I)%M;
			ans++;
		}while(L0!=L);
		cout<<"Case "<<n<<": "<<ans<<endl;
	}
	return 0;;
}
