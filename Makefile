# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elkan <elkan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 21:52:11 by elkan             #+#    #+#              #
#    Updated: 2026/01/17 17:16:27 by elkan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = get_path.c pipex.c pipex_utils.c

OBJECTS = $(SOURCES:%.c=%.o)

NAME = pipex

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Ilibft -g

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) pipex.h
	cc $(OBJECTS) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

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
