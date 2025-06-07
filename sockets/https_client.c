/* This program uses a socket to download the google homepage.
June 7, 2025
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOST "ucalendar.uwaterloo.ca"
#define PORT "443"
#define PATH "/2223/COURSE/course-ECE.html"
#define BUFFER_SIZE 8192

int main()
{
    int sock;
    struct addrinfo hints, *res;
    SSL_CTX *ctx;
    SSL *ssl;
    char request[1024];
    char response[BUFFER_SIZE];

    // 1. Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    // 2. Create SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx)
    {
        fprintf(stderr, "SSL_CTX_new failed\n");
        return 1;
    }

    // 3. Resolve host
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(HOST, PORT, &hints, &res) != 0)
    {
        perror("getaddrinfo failed");
        SSL_CTX_free(ctx);
        return 1;
    }

    // 4. Create socket
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0)
    {
        perror("socket");
        freeaddrinfo(res);
        SSL_CTX_free(ctx);
        return 1;
    }

    // 5. Connect to server
    if (connect(sock, res->ai_addr, res->ai_addrlen) != 0)
    {
        perror("connect");
        close(sock);
        freeaddrinfo(res);
        SSL_CTX_free(ctx);
        return 1;
    }
    freeaddrinfo(res);

    // 6. Create SSL object and connect
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0)
    {
        fprintf(stderr, "SSL_connect failed\n");
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // 7. Send HTTPS GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: SimpleCClient/1.0\r\n"
             "Connection: close\r\n"
             "\r\n",
             PATH, HOST);
    SSL_write(ssl, request, strlen(request));

    // 8. Receive and print response
    int bytes;
    while ((bytes = SSL_read(ssl, response, sizeof(response) - 1)) > 0)
    {
        response[bytes] = '\0';
        printf("%s", response);
    }

    // 9. Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return 0;
}
