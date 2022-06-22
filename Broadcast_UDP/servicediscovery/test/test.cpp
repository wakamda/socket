#include "../api/api.h"
#include "../src/ServiceDiscovery.h"

int main()
{
    char a[] = "abc";
    char *s = a;

    int socketfd = createsocket();

    SocketInfo info = parseapi(socketfd);
    

    replyapi(info,s);

    return 0;
}