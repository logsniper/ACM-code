#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef class Instruction{
public:
	int id;
	int period;
	int nowtime;

	bool operator < (const Instruction & it) const{
		bool ret = nowtime > it.nowtime;
		if(nowtime == it.nowtime)	ret = id > it.id;
		return ret;
	}
}Instruction;

int main()
{
	priority_queue<Instruction> inst;
	Instruction instance;
	string tag;
	int K;
	while(cin>>tag){
		if(tag == "#")	break;
		cin>>instance.id>>instance.period;
		instance.nowtime = instance.period;
		inst.push(instance);
	}
	cin>>K;
	while(K--){
		instance = inst.top();
		cout<<instance.id<<endl;
//		cout<<instance.id<<" "<<instance.nowtime<<endl;
		instance.nowtime += instance.period;
		inst.pop();
		inst.push(instance);
	}
	return 0;
}
