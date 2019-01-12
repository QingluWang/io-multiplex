#ifndef _MY_SERVER_H
#define _MY_SERVER_H

int ServerInit(uint16_t port);
void ServerListen(int serverSockId);
void* PthreadHandleMsg(void* para);

#endif