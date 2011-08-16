#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
char morseEncode[26][6]={".-","-...","-.-.","-..",".","..-.","--.",
						"....","..",".---","-.-",".-..","--","-.",
						"---",".--.","--.-",".-.","...","-",
						"..-","...-",".--","-..-","-.--","--.."};
map<string,int> dict;
char morseCode[10004];
char wordBuffer[84];
int dp[10000];
int n;
int main(){
//	freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		dict.clear();
		scanf("%s%d",morseCode,&n);
		for(int i=0;i<n;++i){
			scanf("%s",wordBuffer);
			string newword = "";
			for(int i=0;wordBuffer[i]!='\0';++i){
				newword += string(morseEncode[wordBuffer[i]-'A']);
			}
//			printf("%s\n",newword.c_str());
			dict[newword] += 1;
		}
		memset(dp,0,sizeof dp);
		int len = strlen(morseCode);
		for(int i=0;i<len;++i){
			for(int j=0;j<80&&j<=i;++j){
				memset(wordBuffer,0,sizeof wordBuffer);
				strncpy(wordBuffer,morseCode+i-j,j+1);
				if(dict.find(wordBuffer)!=dict.end()){
//					printf("%d %d %s\n",i-j,i,wordBuffer);
					if(i>j)	dp[i] += dp[i-j-1]*dict[wordBuffer];
					else	dp[i] += dict[wordBuffer];
				}
			}
		}
		printf("%d\n",dp[len-1]);
	}
}
