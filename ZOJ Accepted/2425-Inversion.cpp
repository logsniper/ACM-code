#include <cstdio>
#include <cmath>
typedef struct myList{
	int value;
	struct myList *next;
	struct myList *prev;
}myList;
typedef struct Ret{
	struct myList *ps;
	struct myList *pm;
	struct myList *pe;
}Ret;
myList *head,*tail,*now;
inline void init(){
	head = new(myList);
	head->prev=NULL;
	head->next=NULL;
	now=head;
	for(int i=1;i<50010;++i){
		tail=now;
		now=new(myList);
		now->prev=tail;
		tail->next=now;
	}
	tail=now;
	tail->next=NULL;
}
inline Ret mySwap(long long s,myList *ps,long long e,myList *pe,long long k)
{
	myList *ps0=ps->prev,*ps1=ps;
	myList *pe0=pe,*pe1=pe->next;
	myList *pm0=ps,*pm1=pe;
	long long len = e-s+1;
	if(k<len/2){
		for(int i=1;i<k;++i)	pm0=pm0->next;
		pm1=pm0->next;
	}
	else{
		for(int i=1;i<len-k;++i)	pm1=pm1->prev;
		pm0=pm1->prev;
	}
	if(ps0!=NULL)
		ps0->next=pm1,pm1->prev=ps0;
	else head = pm1,pm1->prev=NULL;
	pe0->next=ps1,ps1->prev=pe0;
	if(pe1!=NULL)
		pm0->next=pe1,pe1->prev=pm0;
	else tail = pm0,pm0->next=NULL;
	Ret ret;
	ret.ps=pm1,ret.pe=pm0,ret.pm=pe0;
	return ret;
}
inline void reverse(myList *ps,myList *pe,long long k)
{
	myList *news0=ps->prev,*news1=pe,*newe0=ps,*newe1=pe->next;
	myList *now=news1;
	for(long long i=0;i<k;++i){
//		printf("rv : %d\n",now->value);
		myList *next=now->prev,*prev=now->next;
		now->next=next;
		now->prev=prev;
		now=next;
	}
	if(news0!=NULL)
		news0->next=news1;
	news1->prev=news0;
	newe0->next=newe1;
	if(newe1!=NULL)
		newe1->prev=newe0;
}
inline void findseq(long long s,myList *ps,long long e,myList *pe,long long inversion)
{
	while(inversion){
		if(inversion==0||e<=s)	break;
		long long len=e-s+1;
		long long k;
		if(inversion<=(len-1)*(len-2)/2){
			k=(long long)(sqrt(double(8*inversion+1))-1)/2;
			if(k*(k+1)/2<inversion)	++k;
			s=e-k;
			ps=pe;
			for(int i=0;i<k;++i)	ps=ps->prev;
		}
		else{
			long long left;
			long long part[2];
			k=inversion-(len-1)*(len-2)/2;
			left=len-k;
			part[0] = k*left;
			part[1] = k*(k-1)/2;
			Ret ret=mySwap(s,ps,e,pe,k);
			ps=ret.ps,pe=ret.pe;
			if(inversion<=part[0]+part[1]){
				s=s+left;
				ps=ret.pm->next;
				inversion=inversion-part[0];
			}
			else{
				reverse(ret.pm->next,pe,k);
				e=s+left-1;
				pe=ret.pm;
				inversion=inversion-part[0]-part[1];
			}
		}
	}
}
int main()
{
//	freopen("input.txt","r",stdin);
	long long n,m;
	init();
	while(scanf("%lld%lld",&n,&m)&&n>0&&m>=0){
		if(m>n*(n-1)/2) continue;
		now=head;
		for(int i=1;i<=n;++i){
			now->value=i;
			now=now->next;
		}
		tail=now->prev;
		findseq(1,head,n,tail,m);
		now=head;
		for(int i=1;i<=n;++i){
			if(i!=1)	printf(" ");
			printf("%d",now->value);
			now=now->next;
		}
		printf("\n");
	}
	while(head!=NULL){
		now=head;
		head=head->next;
		delete(now);
	}
	return 0;
}
