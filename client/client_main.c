#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "my_client.h"
#include "../util/my_util.h"

static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
static const int childProcessCount=7500;

int main(int argc,char* argv[]){
    char buffer[MAX_LEN];  
    bzero(buffer,sizeof(buffer));
    int sockId=ClientConnect(serverAddr,port);
    pid_t pid;
    int i=0;
    for(; i<childProcessCount; i++){
        pid=fork();
        if(0 == pid || -1 == pid)
            break;
    }
    if(0 == pid){
        char buffer[MAX_LEN];
        sprintf(buffer,"%d",i);
        ClientSendMsg(sockId,buffer);
        close(sockId);
        printf("child thread%d send:%s\n",i,buffer);
    }
    else if(-1 == pid){
        perror("client main:child thread create error!");
    }
    else{
        printf("I am parent thread\n");
    }
    sleep(1);
    fflush(stdout);
    return 0;
}
