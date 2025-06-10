#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void scanall(in_addr_t ip){
    // struct hostent * hp ; // holds infrmation like host name , alias, ip addresses 
    struct sockaddr_in srv ;
    int p ,sock ,result;
    char os[40];

    #ifdef __linux__
        os = "Linux \0";
    #ifdef __windows__
        os = "Windows \0";
    #else 
        os = " unknown os \0";
    #endif

    printf("OS of Target machine : %s ",os);

    for (p=1;p <= 10000;p++){
       sock = socket(AF_INET,SOCK_STREAM,0);
       
       srv.sin_family = AF_INET;
       srv.sin_port = htons(p) ;
       srv.sin_addr.s_addr = ip;


       result = connect(sock,(struct sockaddr *) &srv,sizeof(srv));
        
        if (result == 0) 
            printf("Port %d is open \n" , p);
      
        close(sock);
    }

}

void scanbyPort(in_addr_t ip,int port){
    struct sockaddr_in srv ;
    int sock ,result;

       sock = socket(AF_INET,SOCK_STREAM,0);
       
       srv.sin_family = AF_INET;
       srv.sin_port = htons(port) ;
       srv.sin_addr.s_addr = ip;


       result = connect(sock,(struct sockaddr *) &srv,sizeof(srv));

        if (result == 0) 
            printf("Port %d is open \n" , port);
        else{
            printf("Port %d is closed \n" , port);

        }
        close(sock);
    }





int main(int argc, char const *argv[])
{

    char ip[100];
    int ipcheck,choice,port;
    struct sockaddr_in sa;


while(1){
  start:  printf(" ----------------------------------- \n");
    printf("Port Scanner  \n");
    printf(" -----------------------------------\n");

    printf("Insert Server's IP Address ( q to quit ): \n");
    scanf("%s",ip);

    if(strcmp(ip,"q") == 0)
        break;


    printf(" -----------------------------------\n");
    printf("1-Scan all open ports \t \t \t 2-Scan a Port\n");
    scanf("%d",&choice);


    ipcheck = inet_pton(AF_INET, ip, &(sa.sin_addr)); // converts ip inserted from char to sockaddr_in

    if (ipcheck == 1){
        if(choice == 1){
        scanall(sa.sin_addr.s_addr);
        }
        else if (choice == 2)
        {
            printf("insert port number ; \n");
            scanf("%d",&port);
            scanbyPort(sa.sin_addr.s_addr,port);
        }
        else{
            printf(">>insert valid choice \n");
            goto start;
        }
    }
    else
    printf("invalid IP Addresse");
}
    return 0;
}
