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

int TcpCreate(char* serverAddr){
    int sockId=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockId == -1){
        perror("TcpCreate: socket create error");
    }
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(TCP_PORT);
    server.sin_addr.s_addr = inet_addr(serverAddr);

    int ret=connect(sockId,(struct sockaddr*)&server,sizeof(server));
    if(ret == -1){
        perror("TcpCreate: socket connect error");
    }
    return sockId;
}
void TcpSend(int sockId,char buffer[]){
    int charCount=strlen(buffer);
    int sendBytes=send(sockId, buffer, charCount, 0);
    if(sendBytes<0){
        perror("TcpSend: send message error");  
        exit(0); 
    }
    //bzero(buffer,MAX_LEN);
}
void TcpClose(int sockId){
    close(sockId);
}