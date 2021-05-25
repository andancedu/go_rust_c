#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


int main(int argc, char * *argv)
{
    struct timeval tv0, tv1;

    struct sockaddr_in addr;
    int sock;

    addr.sin_family     = AF_INET;
    addr.sin_port       = htons(9998);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buff_send[512] = "Hello";
    char buff_recv[512] = {0};
    int len = sizeof(addr);

    int n = 0;
    int i = 0;

    printf("This is a UDP client\n");

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
      printf("socket error.\n");
      exit(1);
    }

    if (addr.sin_addr.s_addr == INADDR_NONE)
    {
      printf("Incorrect ip address!");
      close(sock);
      exit(1);
    }

    gettimeofday(&tv0, NULL);
    unsigned long lastime = tv0.tv_sec * 1000000000 + tv0.tv_usec; 
    printf("total: %lu, sec:%lu, nao:%u\n", lastime, tv0.tv_sec, tv0.tv_usec);
    //printf("last time is : %lu\n", lastime);

    //while(1){
    for(int a=0; a< 10000000; a++){
        n = sendto(sock, buff_send, strlen(buff_send), 0, (struct sockaddr *) &addr, sizeof(addr));
        /*
        if (n < 0)
        {
          printf("sendto error.\n");
          close(sock);
        }
        */

        /*
        i++;
        gettimeofday(&tv1, NULL);
        unsigned long curtime = tv1.tv_sec * 1000000000 + tv1.tv_usec; 
        if(curtime >= lastime + 1000000000){
            printf("sec:%lu, nao:%u\n", tv1.tv_sec, tv1.tv_usec);
            printf("current time is : %lu, count: %u\n", curtime, i);
            break;
        }
        */
    }

    gettimeofday(&tv1, NULL);
    unsigned long curtime = tv1.tv_sec * 1000000000 + tv1.tv_usec; 
    printf("total:%lu, sec:%lu, nao:%u\n", curtime, tv1.tv_sec, tv1.tv_usec);
    /*
    n = recvfrom(sock, buff_recv, 512, 0, (struct sockaddr *) &addr, &len);
    if (n > 0)
    {
        buff_recv[n] = 0;
        printf("received from sever:");
        puts(buff_recv);
    }
    else if (n == 0)
        printf("server closed.\n");
    else if (n == -1)
        printf("recvfrom error.\n");

    */
    close(sock);

    return 0;
}

