#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include "../util/my_util.h"
#include "../tcp/my_tcp.h"

void ClientConnect(char* serverAddr){
    int sockId=TcpCreate();
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(TCP_SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(serverAddr);

    int ret=connect(sockId,(struct sockaddr*)&server,sizeof(server));
    if(ret == -1){
        perror("ClientConnect: socket connect error");
    }
}
void ClientSendMsg(){

}