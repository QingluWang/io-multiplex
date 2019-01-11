#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "my_server.h"

static const uint16_t port=17989;
int main(int argc,char* argv[]){
    int serverSockId=ServerInit();
    serverListen(port);
    return 0;
}