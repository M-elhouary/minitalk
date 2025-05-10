CC = cc
CFLAGS =  -Wall -Wextra -Werror
SRC = client.c server.c 
OBJ = $(SRC:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)
$(NAME_SERVER): server.o
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): client.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
