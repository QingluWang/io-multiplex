#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <sys/resource.h>
#include "my_client.h"
#include "../util/my_util.h"


static const char serverAddr[]="127.0.0.1";
static const uint16_t port=17989;
static int count = 0;
static int theryNum=0;

void* PthreadSendMsg(void* para){
    int sockFd=ClientConnect(serverAddr,port);
    int seq=*(int*)para;
    //printf("NO.%d pthread's sockFd=%d\n",seq,sockFd);
    char buffer[128]={0};
    sprintf(buffer,"%d",seq);
    ClientSendMsg(sockFd,buffer);
    printf("Send:%s  Count:%d  TheryNum:%d\n",buffer,count++,theryNum);
    pthread_exit(0);
}
int main(int argc,char* argv[]){
    /* 设置每个进程允许打开的最大文件数 */ 
    struct rlimit rt;
    rt.rlim_max = rt.rlim_cur = MAXEPOLLSIZE; 
    if (setrlimit(RLIMIT_NOFILE, &rt) == -1) { 
        perror("ServerListen:setrlimit"); 
        exit(1); 
    }
    int i=0;
    theryNum=atoi(argv[1]);
    for(; i<theryNum; i++){
        pthread_t tid;
        pthread_attr_t attr;
        if(pthread_attr_init(&attr)){
            
        }
        int status=pthread_create(&tid,NULL,PthreadSendMsg,(void*)&i);
        if(status != 0){
            perror("client main:pthread_create error!\n");
        }
        pthread_detach(tid);
        usleep(500);            
    }
    return 0;
}
