# 多线程socket（server）

socket建立链接的过程：

1. server需要建立，绑定套接字，监听端口

```C++
//建立：int socket(int domain, int type, int protocol);
int sock=socket(AF_INET,SOCK_STREAM,0);

//绑定套接字： int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
//bind
    struct sockaddr_in  sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));// 各位清零
    sockAddr.sin_family=AF_INET;
    sockAddr.sin_addr.s_addr=INADDR_ANY;//将主机的无符号长整形数转换成网络字节顺序,INADDR_ANY就是指定地址为0.0.0.0的地址，这个地址事实上表示不确定地址，或“所有地址”、“任意地址”。
    sockAddr.sin_port=htons(7000);
    bind(sock,(struct sockaddr*)&sockAddr,sizeof(sockAddr));

//监听端口：int listen(int sockfd, int backlog);
listen(sock,10);
```

2. client需要创建，绑定server端的IP，port，最后连接（注册）到server

```C++
int sock=socket(AF_INET,SOCK_STREAM,0);

		struct sockaddr_in sockAddr;
        bzero(&sockAddr,sizeof(sockAddr));//各位清零
        sockAddr.sin_family=AF_INET;
        sockAddr.sin_addr.s_addr=inet_addr("10.20.45.124");  //服务器ip，inet_addr用于IPv4的IP转换（十进制转换为二进制）
        sockAddr.sin_port=htons(7000);
       
conn=connect(sock,(struct sockaddr*)&sockAddr,sizeof(sockAddr))
```

3. 至此，client和server链接成功，开始发送。



# 问题

1. 时序问题
2. socket创建到销毁的阶段
3. socket是阻塞的吗















传统的socket是指，一个client连接一个server，双方通信结束后第二个client才可以连接。