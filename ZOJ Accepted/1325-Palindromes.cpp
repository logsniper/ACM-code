#include<cstdio>
#include<cstring>
using namespace std;
char mirror[]="12358AEHIJLMOSTUVWXYZ";
int pair[]={0,13,6,20,4,5,2,7,8,10,9,11,12,1,14,15,16,17,18,19,3};
const int num=21;

int bsearch(char a)
{
	int first=0,last=num-1,mid;
	while(first<=last){
		mid=(first+last)/2;
		if(mirror[mid]==a)	return mid;
		else if(a<mirror[mid])	last=mid-1;
		else first=mid+1;
	}
	return -1;
}

int main()
{	
	int n,i;
	int a,b;
	char word[21];
	bool mirrored,palindrome;
	while(scanf("%s",word)!=EOF){
		n=strlen(word);

		palindrome=1;
		for(i=0;i<n/2;i++)
			if(word[i]!=word[n-1-i]){
				palindrome=0;
				break;
			}

		mirrored=1;
		for(i=0;i<(n+1)/2;i++){
			a=bsearch(word[i]);
			b=bsearch(word[n-1-i]);
			if(a==-1||b==-1||pair[a]!=b){
				mirrored=0;
				break;
			}
		}

		if(mirrored&&palindrome)
			printf("%s -- is a mirrored palindrome.\n\n",word);
		else if(mirrored&&(!palindrome))
			printf("%s -- is a mirrored string.\n\n",word);
		else if((!mirrored)&&palindrome)
			printf("%s -- is a regular palindrome.\n\n",word);
		else
			printf("%s -- is not a palindrome.\n\n",word);
	}
	return 0;
}
