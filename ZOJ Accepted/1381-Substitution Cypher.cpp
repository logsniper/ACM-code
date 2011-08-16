#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char plaintext[68],substitution[68];
int main()
{
//	freopen("input.txt","r",stdin);
	char nowline[68];
	while(cin.getline(plaintext,68)){
		cin.getline(substitution,68);
		cout<<substitution<<endl<<plaintext<<endl;
		int len=strlen(plaintext);
		while(cin.getline(nowline,68)){
			int nowlen = strlen(nowline);
			for(int i=0;i<nowlen;++i)
				for(int j=0;j<len;++j)
					if(nowline[i]==plaintext[j]){
						nowline[i]=substitution[j];
						break;
					}
			cout<<nowline<<endl;
		}
	}
	return 0;
}
