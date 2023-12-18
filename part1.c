#include "constantheader.h"


int main(int argc, char* argv[]) {
    if (argc != 4) {
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
    
        int fdsocket = socket(res->ai_family, SOCK_DGRAM, IPPROTO_UDP);

        printf("Found :\n");
        printf("\tai-family: %s\n", (res->ai_family) == AF_INET6 ? "AF_INET6" : "AF_INET");
        printf("\tai-socktype: %d\n", res->ai_socktype);
        printf("\tai-protocol: %s\n", (res->ai_protocol == IPPROTO_TCP) ? "IPPROTO_TCP" : "IPPROTO_IP");

        status = getnameinfo(res->ai_addr, res->ai_addrlen, bufferHostName, sizeof(bufferHostName), NULL, 0, NI_NUMERICHOST | NI_NUMERICSERV);
        char rrq[128] = {0};
        sprintf(rrq + 1, "\1%s netascii", argv[3]);
        rrq[strlen(argv[3]) + 2] = 0;

        if (status != 0) {
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));
        } else {
            printf("Host: %s\n", bufferHostName);

            if(sendto(fdsocket, rrq, strlen(argv[3]) + 12, 0, res->ai_addr, res->ai_addrlen)==-1)
            {printf("error");}
        }
        int numberReadBytes;
        char ReceivedBuffer[1024];
        struct sockaddr socketReceived;
        int socketReceivedSize;
        numberReadBytes=recvfrom(fdsocket, ReceivedBuffer, 1024, 0,res->ai_addr,&(res->ai_addrlen));

        if(ReceivedBuffer[2]==3){

            char ackPacket[4]={0};
            int file = open(argv[3], O_CREAT | O_WRONLY |O_TRUNC,S_IRWXU|S_IRWXG|S_IRWXO);
            write(file,ReceivedBuffer+4,numberReadBytes-4);
            while(numberReadBytes==516)
            {
            ackPacket[1]=4;
            ackPacket[2]=ReceivedBuffer[2];
            ackPacket[3]=ReceivedBuffer[3];
            if(sendto(fdsocket, ackPacket, 4, 0, res->ai_addr, res->ai_addrlen)==-1)
            {printf("error");}
            numberReadBytes=recvfrom(fdsocket, ReceivedBuffer, 1024, 0,res->ai_addr,&(res->ai_addrlen));
             write(fdsocket,ReceivedBuffer+4,numberReadBytes-4);
        }
            
            
        }

  
		
			   return EXIT_SUCCESS;	
	}
    

 

