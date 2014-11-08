
SHELL = bash
INCLUDE =
LIBS =

CFLAGS = -Wall -I $(INCLUDE) $(DEBUG) -std=gnu9x

CC = gcc

SRCS_server = server.c
SRCS_client = client.c

OBJS_server := $(SRCS_server:.c=.o)
OBJS_client := $(SRCS_client:.c=.o)

all: server client

server: $(OBJS_server)
	$(CC) $(CFLAGS) $(OBJS_server) $(LIBS) -o server

client: $(OBJS_client)
	$(CC) $(CFLAGS) $(OBJS_client) $(LIBS) -o client

clean:
	rm -f $(OBJS_client) $(OBJS_server) client server
