#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

namespace Webserver{
    //
    int Connections = 100;
    int port = 80;
    char IP[10] = "127.0.0.5";
    char Request[34] = "GET ME A FUCKING WEBPAGE PLASE...";
    //
    int StressTest_WebServer(){
        int Server_Socket = socket(AF_INET, SOCK_STREAM, 0);
        // Is server socket ready??
        if (Server_Socket < 0) { perror("Socket Error: Failed To Make Socket"); exit(1); } 
        struct sockaddr_in ServerAddress;
        ServerAddress.sin_family = AF_INET;
        ServerAddress.sin_addr.s_addr = inet_addr(IP);
        ServerAddress.sin_port = htons(port);
        // Connect
        for (int i = 0; i<Connections; i++){
            int Connect = connect(Server_Socket, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress));
            send(Connect, Request, sizeof(Request), 0);
            close(Connect);
            printf("Sent Connection: Request-%s\n", Request);
            sleep(1);
        }    
        return 0;
    }
    // 
}