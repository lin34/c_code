#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOSTNAME "www.reddit.com"
#define PORT 443

int main()
{
    SSL_library_init();
    SSL_load_error_strings();
    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    if (!ctx)
    {
        perror("Unable to create SSL context");
        return 1;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(HOSTNAME);
    if (!host)
    {
        perror("DNS lookup failed");
        SSL_CTX_free(ctx);
        return 1;
    }

    // Create TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket creation failed");
        SSL_CTX_free(ctx);
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) != 0)
    {
        perror("Connection failed");
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Wrap the socket with SSL
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0)
    {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Send HTTPS GET request
    const char *request =
        "GET / HTTP/1.1\r\n"
        "Host: www.reddit.com\r\n"
        "Connection: close\r\n\r\n";
    SSL_write(ssl, request, strlen(request));

    // Read and print the response
    char buffer[4096];
    int bytes;
    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }

    // Cleanup
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    return 0;
}
