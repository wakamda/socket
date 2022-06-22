#include "../src/ServiceDiscovery.h"

int createsocket(){
    ServiceDiscoveryClass *sd = new ServiceDiscoveryClass();

    return sd->createUdpSocket();
}

SocketInfo parseapi(int fd){
    ServiceDiscoveryClass *sd = new ServiceDiscoveryClass();
    return sd->parse(fd);
}

int replyapi(SocketInfo info,char *sendbuffer){
    ServiceDiscoveryClass *sd = new ServiceDiscoveryClass();
    return sd->reply(info,sendbuffer);
}

