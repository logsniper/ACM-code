#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

class xy
{
public :
	int x,y;
	int k,n; //k:LCM/GCD  n:result
public :
	int input();
	int clc1();
	int clc2();
};


int xy::clc1()
{
	if(y%x) return 0;
	n=1;
	for(int i=0;i<xy::clc2();i++)
		n*=2;
	return n;
}

int xy::clc2()
{
	k=y/x;
	int l=0;
	for(int i=2;i<=k;i++){
		if(!(k%i)) {
			while(!(k%i))
				k/=i;
			l++;
		}		
	}
	return l;
}

/*
int xy::isprime(int tmp)
{
	float j=sqrt(tmp);
	for(int i=2;i<=j;i++){
		if(!(tmp%i)) 	return 0;
	}
	return 1;
}*/

int main()
{
	class xy pq;
	while((	scanf("%d%d",&pq.x,&pq.y)	)!=EOF)
		cout<<pq.clc1()<<endl;
}
