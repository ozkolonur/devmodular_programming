CONFIG_CLIENT_HELLO=y
CONFIG_CLIENT_HTTP_GET=y

TARGET=agent
CC=gcc
CFLAGS=-Wall
LDFLAGS=

OBJS-y = main.o
OBJS-$(CONFIG_CLIENT_HELLO) += client_hello.o
OBJS-$(CONFIG_CLIENT_HTTP_GET) += client_http_get.o

$(TARGET): $(OBJS-y)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS-y) $(LDFLAGS)

all:
	gcc main.c client_hello.c -o agent

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(TARGET) $(OBJS-y)
