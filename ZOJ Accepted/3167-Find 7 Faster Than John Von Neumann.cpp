#include<iostream>
#include<cstring>
using namespace std;
void multiply(char a[],int K,int M)
{
	int len=strlen(a);
	int i;
	char ans[1001];
	int add=0;
	for(i=0;(i<len||add!=0)&&i<=K;i++){
		if(i>=len){
			ans[i]=add%10+'0';
			add/=10;
			continue;
		}
		int tmp=(a[i]-'0')*M+add;
		ans[i]=tmp%10+'0';
		add=tmp/10;
	}
	ans[i]='\0';
	len=strlen(ans);
	for(i=0;i<len;i++){
		a[i]=ans[i];
	}
	a[len]='\0';
}

int main()
{
	int K,M;
	char a[1001];
	while(cin>>K>>M){
		int i=0;
		for(int tmp=M;tmp!=0;tmp/=10)
			a[i++]=tmp%10+'0';
		a[i]='\0';
		int n=1;
		if(i<K-1)
			a[K-1]='0';
		while(a[K-1]!='7'){
			multiply(a,K,M);
			n++;
		}
		cout<<n<<endl;
	}
	return 0;
}
