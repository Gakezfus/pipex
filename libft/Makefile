# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elkan <elkan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/29 13:41:03 by elkan             #+#    #+#              #
#    Updated: 2025/12/29 13:41:03 by elkan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ft_atoi.c ft_atoll.c ft_bzero.c ft_calloc.c ft_idim.c \
ft_int_arr_dup.c ft_intchr.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
ft_lstsize_bonus.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_printf.c ft_prt_hex.c ft_prtchar.c ft_prtnbr.c ft_prtptr.c \
ft_prtstr.c ft_prtuint.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_set_zero.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_utoa.c ft_utohextoa.c get_next_line.c get_next_line_utils.c \
ft_merge_strings.c ft_t_list_to_array.c ft_flush.c ft_free_arrays.c

OBJECTS = $(SOURCES:%.c=%.o)

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

src:
	echo $(wildcard *.c)

$(NAME): $(OBJECTS) libft.h
	ar rcs libft.a $(OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f libft.a

re: fclean all
