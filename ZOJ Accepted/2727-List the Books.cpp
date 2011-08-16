#include <cstdio>
#include <cstdlib>
#include <cstring>
struct ggg{
	char name[84];
	int year,price;
};
int comp1(const void *a,const void *b)
{
	int ret=strcmp(((ggg*)a)->name,((ggg*)b)->name);
	if(ret==0)	ret=((ggg*)a)->year-((ggg*)b)->year;
	if(ret==0)	ret=((ggg*)a)->price-((ggg*)b)->price;
	return ret;
}
int comp2(const void *a,const void *b)
{
	int ret=((ggg*)a)->year-((ggg*)b)->year;
	if(ret==0)	ret=strcmp(((ggg*)a)->name,((ggg*)b)->name);
	if(ret==0)	ret=((ggg*)a)->price-((ggg*)b)->price;
	return ret;
}
int comp3(const void *a,const void *b)
{
	int	ret=((ggg*)a)->price-((ggg*)b)->price;
	if(ret==0) ret=strcmp(((ggg*)a)->name,((ggg*)b)->name);
	if(ret==0)	ret=((ggg*)a)->year-((ggg*)b)->year;
	return ret;
}
ggg list[100];
int n;
int main()
{
	char type[8];
	bool space=false;;
	while(scanf("%d",&n)&&n>0){
		for(int i=0;i<n;++i)
			scanf("%s%d%d",list[i].name,&list[i].year,&list[i].price);
		scanf("%s",type);
		if(strcmp(type,"Name")==0)	qsort(list,n,sizeof(ggg),comp1);
		else if(strcmp(type,"Year")==0)	qsort(list,n,sizeof(ggg),comp2);
		else if(strcmp(type,"Price")==0)	qsort(list,n,sizeof(ggg),comp3);
		if(space)	printf("\n");
		for(int i=0;i<n;++i)
			printf("%s %d %d\n", list[i].name,list[i].year,list[i].price);
		space=true;
	}
	return 0;
}