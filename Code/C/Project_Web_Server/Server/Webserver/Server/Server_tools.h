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
//
namespace Server{
    namespace Webserver{
        class Tools{
            public:
            int Count(char filename[MAX_FILE_NAME]){
                FILE* fp;
            
                // Character counter (result)
                int count = 0;
            
                char filename[MAX_FILE_NAME];
            
                // To store a character read from file
                char c;

                // Open the file
                fp = fopen(filename, "r");
            
                // Check if file exists
                if (fp == NULL) {
                    printf("Could not open file %s",
                        filename);
                    return 0;
                }
            
                // Extract characters from file
                // and store in character c
                for (c = getc(fp); c != EOF; c = getc(fp))
            
                    // Increment count for this character
                    count = count + 1;
            
                // Close the file
                fclose(fp);
            
                // Print the count of characters
                printf("The file %s has %d characters\n ", filename, count);
                return count;
            }
        };
    }
}