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
#define MAX_FILE_NAME 100
// http
char http_head_200[1300] = "HTTP/1.1 200\r\n\n"; /* <--- is good*/
char http_head_404[20] = "HTTP/1.1 404\r\n\n";   /* <--- is BAD : ( */
// server
char ServerBUF[800];
int Server_Socket, Client_Socket;

char* html_data(const char* path){
    FILE* fp = fopen(path, "r");
    if (!fp) { printf("Error loading file '%s'\n", path); return NULL; }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp); fseek(fp, 0, SEEK_SET);
    //
    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    fread(buf, sizeof(char), size, fp); fclose(fp);
    //
    buf[size] = '\0';
    return buf;
   // strcat(http_head_200, buf);
    //send(Client_Socket, http_head_200, sizeof(http_head_200), 0);
    //fclose(fp);
};

// other 
FILE* Page;

FILE *fp;
char Json_buffer[1024];



void Start_Server(char IP[200])
{
    printf("Starting Server...\n");
    printf("Server IP: %s\n", IP);
    printf("Server PORT: %i\n", 80);

    Server_Socket = socket(AF_INET, SOCK_STREAM, 0);
    if (Server_Socket < 0) 
    { 
        perror("Socket Error: Failed To Make Socket"); 
        exit(1); 
    } 

    // Setup socket
    struct sockaddr_in Server_Address, Client_Address;
    Server_Address.sin_family = AF_INET;
    Server_Address.sin_port = htons(80);
    Server_Address.sin_addr.s_addr = INADDR_ANY;

    if (bind(Server_Socket, (struct sockaddr *) &Server_Address, sizeof(Server_Address)) == -1)
    {
        perror("\nSocket Error: Failed To Bind IP/Port"); 
        close(Server_Socket); 
        exit(1);
    }
    if (listen(Server_Socket, 5) == -1)
    { 
        perror("\nSocket Error: Failed To Listen On IP/Port"); 
        close(Server_Socket);
        exit(1);
    }


    while (1){
        printf("\nWaiting for connections\n");
        Client_Socket = accept(Server_Socket, NULL, NULL);
        memset(ServerBUF, 0, 800);
        ServerBUF[800] = '\0';

        printf("\n= = = = = New Connection = = = = = \n");
        read(Client_Socket, ServerBUF, 800);
        printf("\nClient:\n%s", ServerBUF);

        // Get Pages
        if (!strncmp(ServerBUF, "GET /index.html", 15)){
            strcat(http_head_200, html_data("WebPage/index.html"));
            send(Client_Socket, http_head_200, 2000, 0);

            printf("index.html - Sent");

            close(Client_Socket);
        }
    }
}
