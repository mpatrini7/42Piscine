CC	= gcc -g
LIBC	= ar rc
CFLAGS	+= -Wall -Werror -Wextra
OPTFLAGS= -O3
SRC	= .
INCLUDES= -I $(SRC)
LDFLAGS	= -L .i
SRC	= 	main.c doctor_who.c la_casa_di_papel.c lucifer.c squid_game.c stanger_things.c
OBJS	= $(SRC:.c=.o)
NAME	= BSQ

.PHONY: all clean fclean re norma
.SECONDARY: $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OPTFLAGS) $^ -o $@

.o: .c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPTFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f *~ $(NAME)

re: fclean all
