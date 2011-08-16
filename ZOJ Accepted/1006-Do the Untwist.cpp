// First convert the letters in plaintext to integer codes in plaincode according 
// to the following rule: '_' = 0, 'a' = 1, 'b' = 2, ..., 'z' = 26, and '.' = 27. 
// Next, convert each code in plaincode to an encrypted code in ciphercode 
// according to the following formula: for all i from 0 to n - 1,
//
//    ciphercode[i] = (plaincode[ki mod n] - i) mod 28.

#include<cstdio>
#include<string.h>
#define NUMBER 1000
using namespace std;
int CtoP(int c,int i,int n,int key)
{
	int tmp=c+i;
	while(tmp>=28)
		tmp-=28;
	return tmp;
}
int main()
{
	int plaincode[NUMBER],ciphercode[NUMBER];
	char plaintext[NUMBER],ciphertext[NUMBER];
	int key,n,i,tmp;
	while(scanf("%d",&key)&&key!=0){
		scanf("%s",ciphertext);
		n=strlen(ciphertext);
		for(i=0;i<n;i++){
			if(ciphertext[i]=='_')	ciphercode[i]=0;
			else if(ciphertext[i]=='.')	ciphercode[i]=27;
			else ciphercode[i]=ciphertext[i]-'a'+1;
			
			plaincode[key*i%n]=CtoP(ciphercode[i],i,n,key);
//			printf("%d ",CtoP(ciphercode[i],i,n,key));
			
			if(plaincode[key*i%n]==0)	plaintext[key*i%n]='_';
			else if(plaincode[key*i%n]==27)	plaintext[key*i%n]='.';
			else plaintext[key*i%n]='a'+plaincode[key*i%n]-1;
		}
		plaintext[n]='\0';
//		printf("\n");
		printf("%s\n",plaintext);
	}
	return 0;
}
