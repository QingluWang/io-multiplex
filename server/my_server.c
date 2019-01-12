#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include "../util/my_util.h"
#include "../tcp/my_tcp.h"

int ServerInit(uint16_t port){
    int sockId=TcpCreate();
    int set = 1;  
    setsockopt(sockId, SOL_SOCKET, SO_REUSEADDR, &set, sizeof(int)); 
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    socklen_t addr_len = sizeof(server);

    if(bind(sockId,(struct sockaddr*)&server,sizeof(server)) < 0){
        perror("ServerInit: socket bind error");
    };
    if(listen(sockId,4) < 0){
        perror("ServerInit: socket listen error");
    };
    return sockId;
}
void ServerListen(int serverSockId){
    while(1){
        struct sockaddr_in client;
        socklen_t   length = sizeof(client);
        int clientSockId = accept(serverSockId, (struct sockaddr*)&client, &length);
        if (clientSockId < 0)
        {
            printf("ServerListen:server accept failed!\n");
            break;
        }

        char buffer[MAX_LEN];
        bzero(buffer, sizeof(buffer));
        length = recv(clientSockId, buffer, MAX_LEN, 0);
        if (length < 0)
        {
            printf("ServerListen:server recieve data failed!\n");
            break;
        }
        printf("Received:%s\n",buffer);
    }
}