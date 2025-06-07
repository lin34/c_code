## instructions to run this example

gcc -o multi_client_server multi_client_server.c -pthread
gcc -o basic_client basic_client.c

### start the server

./multi_client_server

### open multiple terminals and run:

./basic_client
