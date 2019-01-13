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
static const int childProcessCount=1000;
int main(int argc,char* argv[]){
    pid_t pid;
    int n=0;
    for(; n<childProcessCount; n++){
        pid=fork();
        if(0 == pid || -1 == pid)
            break;
    }
    if(-1 == pid)
        printf("NO.%d fork error!\n",n);
    else if(0 == pid){
        char buffer[MAX_LEN];  
        bzero(buffer,sizeof(buffer));
        int sockId=ClientConnect(serverAddr,port);
        int sendNum=RandomNum(childProcessCount);
        sprintf(buffer,"%d",sendNum);
        ClientSendMsg(sockId,buffer);
        close(sockId);
        printf("Send:%s\n",buffer);
        return 0;
    }
    return 0;
}