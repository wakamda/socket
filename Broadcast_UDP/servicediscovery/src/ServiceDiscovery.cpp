#include "ServiceDiscovery.h"

#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>

int ServiceDiscoveryClass::createUdpSocket(){
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(BIND_PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    int m_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(m_socket == -1)
    {
        perror("socket");
        printf("error in socker()\n");
        exit(0);
    }
    
    int ret = bind(m_socket, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("bind");
        printf("error in bind()\n");
        exit(0);
    }

    return m_socket;
}

SocketInfo ServiceDiscoveryClass::parse(int sockfd){
    struct sockaddr_in cli_addr;
	socklen_t addrlen = sizeof(cli_addr);
	int option_value;
	socklen_t  length;
    char * recvBuffer =new char[1024];
    
    
	int len=recvfrom(sockfd,recvBuffer,sizeof(recvBuffer),0,(struct sockaddr*)&cli_addr,&addrlen);

	if (len < 0)
	{
		getsockopt( sockfd, SOL_SOCKET, SO_ERROR, &option_value, &length );
		 
		if(errno == EWOULDBLOCK || errno== EAGAIN ){
			printf("recvfrom timeout.\n");
			exit(1);
		}			
		else{
			printf("recvfrom errno:%d",errno);
			exit(1);
		}		
	}

	SocketInfo info;
	info.ip= inet_ntoa(cli_addr.sin_addr);
	info.port = ntohs(cli_addr.sin_port);

    printf("UdpReceiver receive:%s",recvBuffer);
    //for(int i=0;i<sizeof(recvBuffer);i++)
    //{
    //    printf("%s",this->recvBuffer[i]);
    //}

	printf("\nip:%s\n",inet_ntoa(cli_addr.sin_addr));
    std::cout << "port:" << ntohs(cli_addr.sin_port) << std::endl;

    return info;

}

int ServiceDiscoveryClass::reply(SocketInfo info,char *sendbuffer){
    
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }

    struct sockaddr_in cliaddr;
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = inet_addr(info.ip.c_str());
    cliaddr.sin_port = htons(info.port); 

    sendto(fd, sendbuffer, sizeof(sendbuffer), 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
        
    printf("send:%s",sendbuffer);
    //for(int i = 0;i < sizeof(sendbuffer); i++){
    //    printf("%X",sendbuffer[i]);
    //}
    printf("\n");
        
}