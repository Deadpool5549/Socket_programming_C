#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//this is a tcp server
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main()
{
    char servMessage[100]="hi ,!";
    int servSocket;
    servSocket=socket(AF_INET,SOCK_STREAM,0);

    //define the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9003);
    serverAddr.sin_addr.s_addr=INADDR_ANY;

    //bind soc to IP
    bind(servSocket,(struct sockaddr*) &serverAddr,sizeof(serverAddr));

    //call listen for listening for connections

    listen(servSocket,5);

    int client_socket;
    //accept(server socket,Client address, Size of) returns int
    client_socket=accept(servSocket,NULL,NULL);//both null cuz local machine

    //now we can send and recv data
    char client_name[30];
    recv(client_socket,client_name,sizeof(client_name),0);
    printf("Client name in server2: %s\n",client_name);
    strcat(servMessage,client_name);
    strcat(servMessage,", You have connected to server 2");
    send(client_socket,servMessage,sizeof(servMessage),0);

    //close it
    close(servSocket);
    return 0;
}
