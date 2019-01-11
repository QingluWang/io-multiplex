#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define TCP_PORT 17989
#define MAX_LEN 100
#define SERVER_ADDR "127.0.0.1"

int TcpCreate(char* serverAddr){
    int clientSock;
    char buffer[MAX_LEN];
    
    clientSock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(clientSock == -1){
        perror("tcp_send: socket create error");
    }
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(TCP_PORT);
    server.sin_addr.s_addr = inet_addr(serverAddr);

    int ret;
    ret = connect(clientSock,(struct sockaddr*)&server,sizeof(server));
    if(ret == -1){
        perror("tcp_create: socket connect error");
    }
    return clientSock;
}
void TcpSend(int sockId,char buffer[]){
    int charCount=strlen(buffer);
    int sendBytes=send(sockId, buffer, charCount, 0);
    if(sendBytes<0){
            perror("tcp_send: send file error");  
            exit(0); 
    }
    //bzero(buffer,MAX_LEN);
}
void TcpClose(int sockId){
    close(sockId);
}