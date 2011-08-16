#include<cstdio>
using namespace std;
bool IsHost(char url[],int k){
//	return (url[k]>='A'&&url[k]<='Z')||(url[k]>='a'&&url[k]<='z')
//			||(url[k]>='0'&&url[k]<='9')||(url[k]=='.');
	return (url[k]!=':')&&(url[k]!='/')&&(url[k]!='\0');
}
int main()
{
	int N,t,i,k;
	char url[61];
	char protocol[10],host[61],port[10],path[61];
	bool flag_port,flag_path;
	scanf("%d",&N);
	for(t=1;t<=N;t++){
		port[0]='\0';
		path[0]='\0';
		flag_port=0;flag_path=0;
		scanf("%s",url);
		//protocol
		for(k=0;url[k]!=':';k++)
			protocol[k]=url[k];
		protocol[k]='\0';
		//host
		while(!IsHost(url,k)) k++;
		i=0;
		while(IsHost(url,k)){
			host[i++]=url[k++];
		}
		host[i]='\0';
		//port
		if(url[k]==':'){
			k++;
			i=0;
			while(url[k]!='/'&&url[k]!='\0'){
				port[i++]=url[k++];
			}
			port[i]='\0';
			flag_port=1;
		}
		//path
		if(url[k]=='/'){
			k++;
			i=0;
			while(url[k]!='\0'){
				path[i++]=url[k++];
			}
			path[i]='\0';
			flag_path=1;
		}
		//output
		printf("URL #%d\n",t);
		printf("Protocol = %s\n",protocol);
		printf("Host     = %s\n",host);
		if(flag_port)
			printf("Port     = %s\n",port);
		else printf("Port     = <default>\n");
		if(flag_path)
			printf("Path     = %s\n\n",path);
		else printf("Path     = <default>\n\n");
		url[0]='\0';
	}
	return 0;
} 
