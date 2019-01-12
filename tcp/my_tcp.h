#ifndef _MY_TCP_H
#define _MY_TCP_H

int TcpCreate();
void TcpSend(int sockId,const char* buffer);
void TcpClose(int sockId);

#endif