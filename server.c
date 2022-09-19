#include<stdlib.h>
#include<stdio.h>
//this is a tcs server
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main()
{
    char servMessage[100]="Yo have connected to server!";
    int servSocket;
    servSocket=socket(AF_INET,SOCK_STREAM,0);

    //define the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9002);
    serverAddr.sin_addr.s_addr=INADDR_ANY;

    //bind soc to IP
    bind(servSocket,(struct sockaddr*) &serverAddr,sizeof(serverAddr));

    //call listen for listening for connections

    listen(servSocket,5);

    int client_socket;
    //accept(server socket,Client address, Size of)
    client_socket=accept(servSocket,NULL,NULL);//both null cuz local machine

    //now we can send and recv data
    send(client_socket,servMessage,sizeof(servMessage),0);

    //close it
    close(servSocket);
    return 0;
}
