/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:39:04 by jpflegha          #+#    #+#             */
/*   Updated: 2025/06/21 14:19:56 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_strcpy(char *dest, const char *src);

int					print_str(char *str);

int					print_digit(long n, int base);

int					print_char(char c);

long				ft_atol(const char *str);

int					ft_isalnum(int i);

int					ft_isdigit(int i);

int					ft_isascii(int i);

int					ft_isalpha(int i);

int					ft_isprint(int i);

size_t				ft_strlen(const char *str);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memmove(void *s1, const void *s2, size_t n);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_atoi(const char *str);

size_t				ft_strlcpy(char *dest, const char *src, size_t ds);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

char				*ft_strchr(const char *s, int c);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

void				*ft_memcpy(void *dest, const void *src, size_t n);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				**ft_split(const char *s, char split);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_printf(const char *str, ...);

int					print_format(char c, va_list ap);

int					check_pointer(unsigned long n, unsigned int base);

char				*get_next_line(int fd);

bool				ft_isspace(char c);

#endif