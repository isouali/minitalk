CFLAGC = -Wall -Wextra -Werror

CC = gcc

c_src = minitalk_utils.c

c_obj=$(c_src:.c=.o)



server = server 
client = client
server_bonus = server_bonus 
client_bonus = client_bonus

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(server) $(client) minitalk.h

bonus : $(server_bonus) $(client_bonus) minitalk_bonus.h

$(client_bonus): $(c_obj) client_bonus.o
	@$(CC) $(CFLAGS) client_bonus.o $(c_obj) -o $(client_bonus)

$(server_bonus): $(c_obj) server_bonus.o
	@$(CC) $(CFLAGS) server_bonus.o $(c_obj) -o $(server_bonus)


$(server): $(c_obj) server.o
	@$(CC) $(CFLAGS) server.o $(c_obj) -o $(server)

$(client): $(c_obj) client.o
	@$(CC) $(CFLAGS) client.o $(c_obj) -o $(client)


clean:
	rm -rf $(c_obj) server.o server_bonus.o client.o client_bonus.o

fclean: clean
	rm -rf $(client) $(server) $(client_bonus) $(server_bonus)

re: fclean all