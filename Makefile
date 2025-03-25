# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude -Ilibft/include

# Source files
CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

# Header files
HEADERS = include/minitalk.h

# Executables
CLIENT = client
SERVER = server

# Libft
LIBFT = libft/libft.a

# Rules
all: $(CLIENT) $(SERVER) 

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	@echo "Building client..."
	$(CC) $(CFLAGS) $(INCLUDE) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	@echo "Building server..."
	$(CC) $(CFLAGS) $(INCLUDE) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	$(MAKE) -C libft

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
