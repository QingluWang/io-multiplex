#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "my_client.h"
#include "../util/my_util.h"

static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
int main(int argc,char* argv[]){
    char buffer[MAX_LEN];  
    bzero(buffer,sizeof(buffer));
    for(int i=0; i<10000; i++){
        int sockId=ClientConnect(serverAddr,port);
        //int num=RandomNum(1000);
        sprintf(buffer,"%d",i);
        ClientSendMsg(sockId,buffer);
        close(sockId);
        printf("Send:%s\n",buffer);
    }
    return 0;
}