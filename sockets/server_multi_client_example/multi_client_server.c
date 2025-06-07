// multi_client_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_CLIENTS 10

void *handle_client(void *arg)
{
    int client_socket = *(int *)arg;
    free(arg);
    char buffer[1024] = {0};

    read(client_socket, buffer, sizeof(buffer));
    printf("Client says: %s\n", buffer);
    send(client_socket, "Hello from multi-client server!", 33, 0);
    close(client_socket);
    return NULL;
}

int main()
{
    int server_fd, *new_sock;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Multi-client server listening on port %d...\n", PORT);

    while (1)
    {
        new_sock = malloc(sizeof(int));
        *new_sock = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (*new_sock < 0)
        {
            perror("Accept failed");
            free(new_sock);
            continue;
        }

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_sock) != 0)
        {
            perror("Thread creation failed");
            close(*new_sock);
            free(new_sock);
        }
        pthread_detach(tid); // Don't need to join
    }

    close(server_fd);
    return 0;
}
