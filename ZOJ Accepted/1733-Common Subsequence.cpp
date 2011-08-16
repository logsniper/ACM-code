#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 1000
int LcsInIJ[MAX][MAX];
int LCS(char a[],char b[],int len_a,int len_b)
{
	if(len_a==0||len_b==0){
		LcsInIJ[len_a][len_b]=0;
		return 0;
	}
	if(LcsInIJ[len_a][len_b]!=-1)	return LcsInIJ[len_a][len_b];
	if(a[len_a-1]==b[len_b-1]){
		LcsInIJ[len_a][len_b]=LCS(a,b,len_a-1,len_b-1)+1;
		return LcsInIJ[len_a][len_b];
	}
	int s=LCS(a,b,len_a-1,len_b-1);
	int s1=LCS(a,b,len_a,len_b-1);
	int s2=LCS(a,b,len_a-1,len_b);
	if(s<s1)	s=s1;
	if(s<s2)	s=s2;
	LcsInIJ[len_a][len_b]=s;
	return s;
}
int main()
{
	char a[MAX],b[MAX];
	int len_a,len_b,i,j;
	while(scanf("%s%s",a,b)!=EOF){
		len_a=strlen(a);
		len_b=strlen(b);
		for(i=0;i<=len_a;i++)
			for(j=0;j<=len_b;j++)
				LcsInIJ[i][j]=-1;
		int rlt=LCS(a,b,len_a,len_b);
//		for(i=0;i<len_a;i++)
//			for(j=0;j<len_b;j++)
//				cout<<LcsInIJ[i][j]<<" ";
		cout<<rlt<<endl;
	}
	return 0;
}
