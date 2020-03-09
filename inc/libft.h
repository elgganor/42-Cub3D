/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:08:02 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/09 08:23:40 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "includes.h"
# include "get_next_line.h"

typedef unsigned char	t_uchar;
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
/*
** ==== checker ====
*/
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_islower(int c);
int				ft_isupper(int c);

/*
** ==== convert ====
*/
int				ft_atoi(const char *str);
int				ft_abs(int i);
char			*ft_itoa(int n);
char			*ft_ltohex(long l);
char			*ft_itohex(long n);
char			*ft_strtoupper(char *s);
unsigned int	ft_itou(int n);
char			*ft_ltoa(long n);
long			ft_atol(char *str);

/*
** ==== linked_list ====
*/
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));

/*
** ==== memory management ====
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);

/*
** ==== display ====
*/
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstrn(char *s);
void			ft_putnbrn(int n);

/*
** ==== string manipulation ====
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *src, const char *sub, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);

#endif
