#ifndef _MY_CLIENT_H
#define _MY_CLIENT_H

int ClientConnect(char* serverAddr,uint16_t port);
void ClientSendMsg(int sockId,char* const buffer);

#endif