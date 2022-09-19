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
	struct sockaddr_in server_address;//predefined struct sockaddr_in used for tcp/ip
	server_address.sin_family=AF_INET;
	//specifing port ,htons() convert int to port type
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr= INADDR_ANY;//is 0.0.0.0
//sin_addr is another structur in sockaddr_in for internet address(32 bit)
	// call connect fun(
	int con_status=connect(sockid, (struct sockaddr*) &server_address,sizeof(server_address));
	//check for error in connection
	if(con_status==-1)
	{
		printf("error\n");
	}

	//call recv(skt,location/str to store data,size,flag) fun to recv data
	char serv_resp[100];
	recv(sockid,serv_resp,sizeof(serv_resp),0);
	printf("\nReceived data from server: %s\n",serv_resp);
	printf("hello\n");

	close(sockid);//close socket 
        return 0;
}

