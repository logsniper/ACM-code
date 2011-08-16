#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
queue<string> q;
int appeared[10000];
int str2int(string s){
	int res = (s[3]-'0')
			+ (s[2]-'0')*10
			+ (s[1]-'0')*100
			+ (s[0]-'0')*1000;
	return res;
}
string plusOne(const string s,int k)
{
	string ret = s;
	if(ret[k]=='9')	ret[k]='1';
	else ++ret[k];
	return ret;
}
string minusOne(const string s,int k)
{
	string ret = s;
	if(ret[k]=='1')	ret[k]='9';
	else --ret[k];
	return ret;
}
void myPush(const string now,int step)
{
	if(!appeared[str2int(now)]){
		q.push(now);
		appeared[str2int(now)]=step;
	}
}
bool find(const string tgt)
{
	string head = q.front();
	q.pop();
	int step = appeared[str2int(head)]+1;
//	cout<<step<<endl;
	string now;
	//swap neighbour
	now = head;
	now[0]=head[1],now[1]=head[0];
	myPush(now,step);
	now = head;
	now[2]=head[1],now[1]=head[2];
	myPush(now,step);
	now = head;
	now[2]=head[3],now[3]=head[2];
	myPush(now,step);
	for(int i=0;i<4;++i){
		//plus one
		now = plusOne(head,i);
		myPush(now,step);
		//minus one
		now = minusOne(head,i);
		myPush(now,step);
	}

//	cout<<q.size()<<endl;
	if(appeared[str2int(tgt)]>0)	return true;
	else return false;
}
int main()
{
	int t;
	cin>>t;
	string from,to;
	while(t--){
		cin>>from>>to;
		if(from==to){
			cout<<"0\n";
			continue;
		}
//		memset(appeared,0,10000);
		for(int i=0;i<10000;++i)
			appeared[i]=0;
		while(!q.empty())	q.pop();
		q.push(from);
		while(!q.empty()&&!find(to));
		cout<<appeared[str2int(to)]<<endl;
	}
	return 0;
}
