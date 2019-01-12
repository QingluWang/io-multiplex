#ifndef _MY_CLIENT_H
#define _MY_CLIENT_H

int ClientConnect(const char* serverAddr,uint16_t port);
void ClientSendMsg(int sockId,const char* buffer);

#endif