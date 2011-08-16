#include<cstdio>
#include<cstring>
#define PRIME 3999971
#define MOD 2147483647
#define MAXN 1000010
class Node{
public:
	char str[8];
	Node *next;
	void init(char *_str){
		strcpy(str,_str);
		next = NULL;
	}
};
Node* table[PRIME];
Node buffer[MAXN];
int used;
void init(){
	memset(table,0,sizeof table);
	used = 0;
}
int hash(char* str){
	int h=0;
	for(int i=0;i<7;++i){
		h = h*127 + str[i];
	}
	h = h&MOD;
	return h%PRIME;
}
Node* find(char *str){
	int h = hash(str);
	Node *p = table[h];
	while(p!=NULL){
		if(strcmp(p->str,str)==0){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void insert(char* str){
	int h = hash(str);
	Node *p = table[h];
	if(p!=NULL){
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = &buffer[used++];
		p->next->init(str);
	}
	else{
		table[h] = &buffer[used++];
		table[h]->init(str);
	}
//	printf("insert : %s\n",table[h]->str);
}
void remove(char* str,Node* t){
	int h = hash(str);
	Node* p = table[h];
	if(p == t){
		table[h] = t->next;
	}
	else{
		while(p!=NULL && p->next!=t){
			p = p->next;
		}
		if(p!=NULL){
			p->next = t->next;
		}
	}
}
void show(){
	for(int i=0;i<PRIME;++i){
		if(table[i]!=NULL){
			printf("%s\n",table[i]->str);
			break;
		}
	}
}
int main(){
	int n;
	char str[8];
	while(scanf("%d",&n)!=EOF){
		getchar();
		init();
		n = n*2-1;
		for(int i=0;i<n;++i){
			gets(str);
			Node *p = find(str);
			if(p == NULL){
				insert(str);
			}
			else{
				remove(str,p);
			}
		}
		show();
	}
}


