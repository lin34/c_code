CC = clang
CFLAGS = -g -Wall

all: curl

curl: libcurl.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	rm -rf curl