#include<stdlib.h>
#include<stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>  // for close()
int main()
{
	//creates network socket
	int sockid;
	sockid=socket(AF_INET, SOCK_STREAM,0);
	//specify address for socket
	struct sockaddr_in servAddr2;
	struct sockaddr_in server_address;//predefined struct sockaddr_in used for tcp/ip
	server_address.sin_family=AF_INET;
	//specifing port ,htons() convert int to port type
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr= INADDR_ANY;//is 0.0.0.0

	servAddr2.sin_family=AF_INET;
	servAddr2.sin_port= htons(9003);
	servAddr2.sin_addr.s_addr=INADDR_ANY;
//sin_addr is another structur in sockaddr_in for internet address(32 bit)
	// call connect fun(
	int con_status=connect(sockid, (struct sockaddr*) &server_address,sizeof(server_address));
	//check for error in connection
	if(con_status==-1)
	{
		printf("error not connected\n");
	}
	char name[30];
	printf("Enter your name: ");
	scanf("%s",name);
	printf("sending name to server!!\n ");
    send(sockid,name,sizeof(name),0);
	//call recv(skt,location/str to store data,size,flag) func to recv data
	char serv_resp[100];
	recv(sockid,serv_resp,sizeof(serv_resp),0);
	printf("\nReceived data from server: %s\n",serv_resp);


	close(sockid);
	sockid=socket(AF_INET, SOCK_STREAM,0);
    con_status=connect(sockid, (struct sockaddr*) &servAddr2,sizeof(servAddr2));
	//check for error in connection
	if(con_status==-1)
	{
		printf("error not connected to server 2\n");
	}

	printf("sending name to server-2!!\n ");
      send(sockid,name,sizeof(name),0);
   char serv_resp2[100]="hi, ";
    recv(sockid,serv_resp2,sizeof(serv_resp2),0);
    printf("\nReceived data from server-2 : %s\n",serv_resp2);
	printf("hello\n");

	close(sockid);//close socket
        return 0;
}


