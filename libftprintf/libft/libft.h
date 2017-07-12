/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:10:05 by jbert             #+#    #+#             */
/*   Updated: 2016/01/11 14:18:02 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# ifdef linux
#  include <stdint.h>
# endif

# include <string.h>

int				ft_atoi(char *s);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
int				ft_putnbr(long long i);
int				ft_putendl(char const *s);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putendl_fd(char const *s, int fd);
int				ft_putchar_fd(char c, int fd);

char			*ft_strcat(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
void			ft_strdel(char **as);
char			*ft_strdup(char *s);
int				ft_strequ(char *s1, char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int i, char *));
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcat(char *dst, char *src, size_t size);
unsigned int	ft_strlen(char *s);
char			*ft_strmap(char *s, char (*f)(char));
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, char *s2, size_t n);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strncpy(char *dst, char *src, unsigned int n);
int				ft_strnequ(char *s1, char *s2, unsigned int n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *s1, char *s2, size_t n);
char			*ft_strrchr(char *s, int c);
char			**ft_strsplit(char *s, char c);
char			*ft_strstr(char *s1, char *s2);
char			*ft_strsub(char *s, unsigned int start, size_t len);
char			*ft_strtrim(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
