#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>//linux下特有的头文件，主要包含了read，write等函数
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MAXLINE 4096
#define PORT 7000

//server的动作：创建socket，绑定端口地址(先设置端口地址)，监听，开始接受accept，然后接收数据，关闭

int main()
{
    //buff
    char buff[4096];
    
    int sock=socket(AF_INET,SOCK_STREAM,0);

    //bind
    struct sockaddr_in  sockAddr;

    memset(&sockAddr,0,sizeof(sockAddr));// 各位清零
    sockAddr.sin_family=AF_INET;
    sockAddr.sin_addr.s_addr=INADDR_ANY;
    sockAddr.sin_port=htons(PORT);
    bind(sock,(struct sockaddr*)&sockAddr,sizeof(sockAddr));

    //listen
    listen(sock,10);

    printf("======waiting for client's request======\n");

    if(int conn=accept(sock,(struct sockaddr*)NULL,NULL) > 0)//已链接的socket标识
    {
        while(1)
        {
            int n=recv(conn,buff,MAXLINE,0);
            buff[n] = '\0';
            printf("recv msg from client: %x\n", buff);
            sleep(1);
        }
        close(conn);
    }

    close(sock);
}