#ifndef _SERVICEDISCOVERY_H_
#define _SERVICEDISCOVERY_H_
#include <string>

typedef struct {
    std::string ip;
    int port;
}SocketInfo;

#define BIND_PORT 50503

class ServiceDiscoveryClass{
    public:

        int createUdpSocket();

        SocketInfo parse(int sockfd);

        int reply(SocketInfo info,char * sendbuffer);

};




#endif //_SERVICEDISCOVERY_H_