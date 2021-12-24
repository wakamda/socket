#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<unistd.h>//linux下特有的头文件，主要包含了read，write等函数
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include<sys/types.h>
#include<pthread.h>
#include<vector>

#define IP_addr "127.0.0.1"
#define LOCAL_PORT 7000

pthread_mutex_t mutex;