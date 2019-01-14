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

int main(int argc,char* argv[]){
    pid_t pid;
    int sockFd=ClientConnect(serverAddr,port);
    ClientSendMsg(sockFd,argv[1]);
    return 0;
}
