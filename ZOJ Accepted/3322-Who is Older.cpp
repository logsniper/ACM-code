#include <cstdio>
int main()
{
	int year[2],month[2],day[2];
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&year[0],&month[0],&day[0],&year[1],&month[1],&day[1]);
		if(year[0]!=year[1]){
			printf("%s\n",year[0]<year[1]?"javaman":"cpcs");
		}
		else if(month[0]!=month[1]){
			printf("%s\n",month[0]<month[1]?"javaman":"cpcs");
		}
		else if(day[0]!=day[1]){
			printf("%s\n",day[0]<day[1]?"javaman":"cpcs");
		}
		else
			printf("same\n");
	}
}