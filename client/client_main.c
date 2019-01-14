#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>
#include "my_client.h"
#include "../util/my_util.h"


static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;

int main(int argc,char* argv[]){
    int sockFd=ClientConnect(serverAddr,port);
    pid_t pid=fork();
    if(pid < 0){
        perror("client_main:create child thread error!");
    }
    else if(pid == 0){
        int receBytes=0;
        char buffer[MAX_LEN];
        memset(buffer,0,sizeof(buffer));
        while((receBytes=recv(sockFd,buffer,MAX_LEN,0)) > 0){
            printf("Receive:%s\n",buffer);
            receBytes=0;
        }
    }
    else{
        ClientSendMsg(sockFd,argv[1]);
    }
    return 0;
}
