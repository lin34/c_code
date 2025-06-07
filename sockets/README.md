requires:
sudo apt-get install libssl-dev

to compile:
gcc -o https_client https_client.c -lssl -lcrypto

- to compile socket.c

# Compile socket.c into an executable named socket_example

gcc -o https_client https_client_openssl.c -lssl -lcrypto

# Run the compiled program

./https_client

## compiling the basic_client basic_server example

gcc -o basic_server basic_server.c
gcc -o basic_client basic_client.c
