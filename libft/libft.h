/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:14:04 by echoo             #+#    #+#             */
/*   Updated: 2025/12/26 17:27:58 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
int				ft_lstsize(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

// ft_printf
int				ft_prtchar(char c, va_list *ap, int *count);
int				ft_printf(const char *s, ...);
int				ft_prtnbr(int n, int *count);
int				ft_prtptr(va_list *ap, int *count, char c);
int				ft_prtstr(char *s, int *count);
int				ft_prtuint(unsigned int n, int *count);
int				ft_prt_hex(char c, uintptr_t num, int *count);
void			ft_utohextoa(uintptr_t num, char *string, char *base);
char			*ft_utoa(unsigned int n);

// GNL
// GNL returns NULL if EOF or if an error occurs. So, GNL cannot detect errors
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char			*get_next_line(int fd);
char			*calc_return(int n_eof, char *buf);
char			*get_next_line(int fd);
int				calc_leftover(char **buf, size_t *len,
					int *newline_index, char **leftover);
int				read_fd(char **buf, size_t *len, int *newline_index, int fd);
int				store_leftover(char **buf, size_t len,
					int newline_index, char **leftover);
int				ft_newline(char *str, int i);
void			ft_gnl_strlcpy(char *dst, const char *src, size_t size);

// OWN FUNCTIONS

long long int	ft_atoll(const char *str);

// n is number of ints, NOT number of bytes
int				*ft_intchr(const int *s, int c, size_t n);

// n is number of ints, NOT number of bytes
int				*ft_int_arr_dup(const int *i, size_t len);

// returns the int difference between x and y
unsigned int	ft_idim(int x, int y);

// sets the value of all ints pointed to by the function to zero
void			ft_set_zero(int num, ...);

// Replaced str_1 with a string of str_1 and str_2 combined. Returns 1 if
// malloc fails. str_1 MUST be freeable.
int				ft_merge_strings(char **str_1, char *str_2);

// Returns an array of elements contained in the linked list that can be freed.
// So, if content points to an int, this will return an array of all ints in
// the linked list
void			*ft_t_list_to_array(t_list *list, size_t content_size);

// Fully reads the file in the file descriptor, ensuring no leftovers remain.
void			ft_flush(int fd);

// Fully frees an array[][]. Array MUST be NULL terminated
void			ft_free_arrays(void **array);

#endif
