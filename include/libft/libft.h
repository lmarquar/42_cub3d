/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:08:33 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/08 12:24:03 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

char			**ft_arradd(const char *const *s1, const char *s2);

char			**ft_arraddn(const char *const *s1, const char *s2, size_t n);

int				ft_arrdel(char **arr);

char			**ft_arrdelline(char **arr, size_t line);

char			**ft_arrdup(const char *const *arr);

char			**ft_arrjoin(const char *const *s1, const char *const *s2);

size_t			ft_arrlen(const char *const *arr);

int				ft_atoi(const char *str);

unsigned long	ft_atounl(const char *str);

void			ft_bzero(void *s, size_t n);

char			*ft_dtoa(double d);

void			*ft_calloc(size_t nmemb, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

char			*ft_unitoa(unsigned int n);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *str1, const void *str2, size_t n);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

void			*ft_memset(void *s, int c, size_t n);

int				ft_power(int nbr, int power);

void			ft_putchar(char c);

void			ft_putendl(char *s);

void			ft_putnbr(int n);

void			ft_putstr(char *s);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s);

char			*ft_strdupn(const char *s, size_t n);

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dest, const char *src, size_t size);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

size_t			ft_strlen(const char *str);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strncmp(const char *str1, const char *str2, size_t n);

char			*ft_strnstr(const char *s1, const char *s2, size_t n);

char			*ft_strrchr(const char *s, int c);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del) (void *));

void			ft_lstclear(t_list **lst, void (*del) (void *));

void			ft_lstiter(t_list *lst, void (*f) (void *));

#endif