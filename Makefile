# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elkan <elkan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 21:52:11 by elkan             #+#    #+#              #
#    Updated: 2026/01/19 03:06:54 by elkan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES = $(addprefix mand/, get_path.c pipex.c pipex_utils.c)

SOURCES = get_path.c pipex.c pipex_utils.c get_heredoc.c commands.c

OBJECTS = $(SOURCES:%.c=%.o)

NAME = pipex

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Ilibft -I. -g

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
