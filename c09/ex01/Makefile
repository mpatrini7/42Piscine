# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 12:19:42 by mpatrini          #+#    #+#              #
#    Updated: 2021/12/16 12:53:38 by mpatrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
LIBC	= ar rc
CFLAGS	+= -Wall -Werror -Wextra
SRC	= 	srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= $(SRC:.c=.o)
NAME	= libft.a

.PHONY: all clean fclean re norma

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f *~ $(NAME)

re: fclean all
