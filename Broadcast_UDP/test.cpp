#include <stdio.h>

int main()
{
    unsigned char a= '1';//char占1字节，存储为0x01
    printf("a-d:%d\n",a);
    printf("a-c:%c\n",a);
    printf("a-x:%X\n",a);

    printf("----------------------\n");

    unsigned char b[2] = {'1','2'};
    printf("d-p:%p\n",b);//b是数组变量名，存储的是数组的起始地址，因此b为指针。b[0]才是第一个元素
    //printf("d-d:%d\n",b);错误
    printf("b-c(p):%c\n",*b);
    printf("b-d:%d\n",b[0]);
    printf("b-c:%c\n",b[0]);
    printf("b-x:%X\n",b[1]);

    printf("----------------------\n");

    unsigned char d[2] = {0x01,0x02};
    printf("d-p:%p\n",d);//d是数组变量名，存储的是数组的起始地址          //printf("d-d:%d\n",d);//错误，d为指针
    printf("d-d(p):%d\n",*d);//*指针 = *地址 = 指向地址 = 对应地址上的值
    printf("d-x:%X\n",*d);
    printf("d-d:%d\n",d[0]);
    printf("d-d:%d\n",d[1]);

    printf("----------------------\n");

    unsigned char e[17] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11};
    printf("d-d:\n");
    for(int i = 0;i < sizeof(e);i++){
        printf("%X",e[i]);
    }
    printf("\n");

    printf("----------------------\n");
    return 0 ;
}