#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "my_client.h"
#include "../util/my_util.h"

static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
int main(int argc,char* argv[]){
    int sockId=ClientConnect(serverAddr,port);
    char buffer[MAX_LEN];
    bzero(buffer,sizeof(buffer));
    int num=RandomNum(1000);
    ClientSendMsg(sockId,itoa(num,buffer,10));
    close(sockId);
    return 0;
}