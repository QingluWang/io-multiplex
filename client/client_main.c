#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include "my_client.h"
#include "../util/my_util.h"

static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
static const int childProcessCount=10;

void* PthreadSendMsg(void* para){
    char buffer[MAX_LEN];
    int sendNum=RandomNum(childProcessCount);
    int sockId=*(int*)para;
    sprintf(buffer,"%d",sendNum);
    ClientSendMsg(sockId,buffer);
    close(sockId);
    printf("Send:%s\n",buffer);
}
int main(int argc,char* argv[]){
    char buffer[MAX_LEN];  
    bzero(buffer,sizeof(buffer));
    int sockId=ClientConnect(serverAddr,port);
    
    for(int i=0; i<childProcessCount; i++){
        pthread_attr_t attr;
        pthread_t threadId;

        pthread_attr_init(&attr);
        pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

        if(pthread_create(&threadId,&attr,PthreadSendMsg,(void*)&(sockId))){
            perror("client_main:pthread create error!\n");
        }
    }
    return 0;
}
