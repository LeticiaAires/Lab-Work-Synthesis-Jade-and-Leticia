#include "constantheader.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Not Right Number\n");
        return EXIT_FAILURE;
    }

    char bufferHostName[128] = {0};
    struct addrinfo hints, *res;
    int status;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    printf("GetAddrInfo on: %s \n", argv[1]);
    getaddrinfo(argv[1], argv[2], &hints, &res);
    struct addrinfo* current;
    current=res;

    while (current != NULL) {
        int fdsocket = socket(current->ai_family, current->ai_socktype, current->ai_protocol);
        
            printf("Found :\n");
            printf("\tai-family: %s\n", (current->ai_family) == AF_INET6 ? "AF_INET6" : "AF_INET");
            printf("\tai-socktype: %d\n", current->ai_socktype);
            printf("\tai-protocol: %s\n", (current->ai_protocol == IPPROTO_TCP) ? "IPPROTO_TCP" : "IPPROTO_IP");

            status = getnameinfo(current->ai_addr, current->ai_addrlen, bufferHostName, sizeof(bufferHostName), NULL, 0, NI_NUMERICHOST | NI_NUMERICSERV);
            char rrq[128] = {0};
            sprintf(rrq + 1, "\1%s netascii", argv[1]);
            rrq[strlen(argv[1]+2)]=0;
            

            if (status != 0) {
                fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));
            } else {
                printf("Host: %s\n", bufferHostName);
                sendto(fdsocket,rrq,strlen(argv[1]+12),0,current->ai_addr,res->ai_addrlen);
               
            }

        
        }

        current = current->ai_next;
    }

    

    return EXIT_SUCCESS;
}

