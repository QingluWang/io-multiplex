#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "my_client.h"

static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
int main(int argc,char* argv[]){
    int sockId=ClientConnect(serverAddr,port);
    ClientSendMsg(sockId,"1");
    close(sockId);
    return 0;
}