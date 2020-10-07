#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int main(int argc, char **argv) {

    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6969); 
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sockfd, &serverAddress, sizeof(serverAddress));
    listen(sockfd, 5);

    while(1) {
        int clientSize = sizeof(clientAddress);
        int clientSocket = accept(sockfd, &clientAddress, &clientSize);
        char c;

        char *message = "kisana.co";
        write(clientSocket, message, strlen(message));

        close(sockfd);
    }

    return 0;
}