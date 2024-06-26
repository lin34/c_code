#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *ignorethis)
{
    size_t bytes = itemsize * nitems;
    int linenumber = 1;
    printf("New chunk (%zu bytes)\n", bytes);
    printf("%d:\t", linenumber);
    for (int i = 0; i < bytes; i++)
    {
        printf("%c", buffer[i]);
        if (buffer[i] == '\n')
        {
            linenumber++;
            printf("%d:\t", linenumber);
        }
    }
    printf("\n\n\n");
    return bytes;
}

int main()
{
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "init failed\n");
        return EXIT_FAILURE;
    }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, "https://lin34.github.io/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
    // perform our action
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK)
    {
        fprintf(stderr, "download problem %s\n", curl_easy_strerror(result));
    }
    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}