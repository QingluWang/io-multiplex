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
    int sockId=ClientConnect(serverAddr,port);
    char buffer[MAX_LEN];    
    int num=RandomNum(1000);
    bzero(buffer,sizeof(buffer));
    sprintf(buffer,"%d",num);
    ClientSendMsg(sockId,buffer);
    close(sockId);
    return 0;
}