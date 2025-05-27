#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>

void scan(in_addr_t ip){
    // struct hostent * hp ; // holds infrmation like host name , alias, ip addresses 
    
    struct sockaddr_in srv ;
    int p ,sock ,result;

    for (p=1;p <= 1023;p++){
       sock = socket(AF_INET,SOCK_STREAM,0);
       
       srv.sin_family = AF_INET;
       srv.sin_port = htons(p) ;
       srv.sin_addr.s_addr = ip;


       result = connect(sock,(struct sockaddr_in *) &srv,sizeof(srv));

        if (result == 0) 
            printf("Port %d is open \n" , p);
        else 
            printf("Port %d is closed \n",p);

    }




}


int main(int argc, char const *argv[])
{

    in_addr_t ip;


    printf(" ----------------------------------- \n");
    printf("Port Scanner  \n");
    printf(" -----------------------------------\n");


    printf("insert  Server \'s  IP address : \n");
    scanf("%d",&ip);


    scan(ip);


    return 0;
}
