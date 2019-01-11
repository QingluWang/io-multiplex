#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int TcpCreate(){
    int sockId=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockId == -1){
        perror("TcpCreate: socket create error");
    }
    return sockId;
}
void TcpSend(int sockId,const char* buffer){
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