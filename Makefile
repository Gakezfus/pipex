# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elkan <elkan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 21:52:11 by elkan             #+#    #+#              #
#    Updated: 2026/01/16 01:03:10 by elkan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=%.o)

NAME = pipex

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Ilibft -g

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) pipex.h
	cc $(OBJECTS) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

src: $(SOURCES)
	echo $(SOURCES)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

-include $(SRC:%.c=%.d)

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
