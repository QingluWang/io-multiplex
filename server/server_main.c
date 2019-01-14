#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "my_server.h"

static const uint16_t port=17989;
int main(int argc,char* argv[]){
    //daemon(0,0);
    int serverSockId=ServerInit(port);
    ServerListen(serverSockId);
    close(serverSockId);
    return 0;
}