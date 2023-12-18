Certainly! Below are comments added to your code for better understanding:

```c
#include "constantheader.h"

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 4) {
        printf("Not the correct number of arguments\n");
        return EXIT_FAILURE;
    }

    // Initialize variables for host information and status
    char bufferHostName[128] = {0};
    struct addrinfo hints, *res;
    int status;

    // Initialize and set the address hints
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    // Display information about the target host
    printf("GetAddrInfo on: %s \n", argv[1]);

    // Obtain address information for the target host
    getaddrinfo(argv[1], argv[2], &hints, &res);

    // Create socket base on the obtained address information
    int fdsocket = socket(res->ai_family, SOCK_DGRAM, IPPROTO_UDP);

    // Display details about the found address information
    printf("Found :\n");
    printf("\tai-family: %s\n", (res->ai_family) == AF_INET6 ? "AF_INET6" : "AF_INET");
    printf("\tai-socktype: %d\n", res->ai_socktype);
    printf("\tai-protocol: %s\n", (res->ai_protocol == IPPROTO_TCP) ? "IPPROTO_TCP" : "IPPROTO_IP");

    // Resolve the address to a numeric form
    status = getnameinfo(res->ai_addr, res->ai_addrlen, bufferHostName, sizeof(bufferHostName), NULL, 0, NI_NUMERICHOST | NI_NUMERICSERV);

    // Build the Read Request (RRQ) packet for TFTP
    char rrq[128] = {0};
    sprintf(rrq + 1, "\1%s netascii", argv[3]);
    rrq[strlen(argv[3]) + 2] = 0;

    // Check if the numeric resolution was successful
    if (status != 0) {
        fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));
    } else {
        // Display the resolved host information
        printf("Host: %s\n", bufferHostName);

        // Send the RRQ packet to the server using UDP
        if (sendto(fdsocket, rrq, strlen(argv[3]) + 12, 0, res->ai_addr, res->ai_addrlen) == -1) {
            printf("Error sending RRQ packet\n");
        }
    }

    // Read the response from the server
    int numberReadBytes;
    char ReceivedBuffer[1024];
    struct sockaddr socketReceived;
    int socketReceivedSize;
    numberReadBytes = recvfrom(fdsocket, ReceivedBuffer, 1024, 0, res->ai_addr, &(res->ai_addrlen));

    // Check if the received packet is a data packet
    if (ReceivedBuffer[2] == 3) {
        // Prepare an acknowledgment packet for data reception
        char ackPacket[4] = {0};
        int file = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
        write(file, ReceivedBuffer + 4, numberReadBytes - 4);

        // Continue receiving data packets and sending acknowledgments
        while (numberReadBytes == 516) {
            ackPacket[1] = 4;
            ackPacket[2] = ReceivedBuffer[2];
            ackPacket[3] = ReceivedBuffer[3];

            // Send acknowledgment packet
            if (sendto(fdsocket, ackPacket, 4, 0, res->ai_addr, res->ai_addrlen) == -1) {
                printf("Error sending acknowledgment packet\n");
            }

            // Receive the next data packet
            numberReadBytes = recvfrom(fdsocket, ReceivedBuffer, 1024, 0, res->ai_addr, &(res->ai_addrlen));

            // Write the data to the file
            write(fdsocket, ReceivedBuffer + 4, numberReadBytes - 4);
        }
    }

    // Close the socket and return success
    close(fdsocket);
    return EXIT_SUCCESS;
}
