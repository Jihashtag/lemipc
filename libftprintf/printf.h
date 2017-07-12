/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 04:04:19 by jbert             #+#    #+#             */
/*   Updated: 2015/06/05 10:41:46 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H
# define _PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <wchar.h>

# define ISINT(c) (c == 'd' || c == 'i' || c == 'D')

typedef	struct	s_args
{
	unsigned int	arg_size;
	void			*args;
}				t_args;

void			*memdup(void *or, unsigned long int n);
int				ft_wstrlen(wchar_t *wstr);
intmax_t		s1n(va_list ap, int *f);
intmax_t		s1u(va_list ap, int *f);
intmax_t		ft_supzero(void *i, char c, int f);
uintmax_t		ft_usupzero(void *i, int f);

int				ft_d_i(void *arg, int f);
int				ft_s_c(char c, void *arg, int f);
int				ft_o(void *arg, int *f, char c);

int				ft_base(void *arg, int f, char *s);
int				write_base(void *arg, char w, int *f);
int				write_c(void *arg, char c, int f);

int				ft_putwchar(wchar_t c);
int				ft_putbase(uintmax_t nb, char *s);
int				ft_putwstr(wchar_t *s);

int				ft_putsp(int no_w, int *f, int j);
void			fst_inc(char *s, int *j, int *tb);
void			increm(int *j, int *count);
void			my_while(char *s, int *j, int *count, int *tb);

int				ft_0x(char c, int *f, t_args args);
int				ft_spec(t_args args, char c, int *f);
int				ft_treatment(char *s, int j, va_list ap, int *f);

int				ft_printf(char *s, ...);

t_args			getslen(va_list ap, int *f);
t_args			getnlen(va_list ap, int *f);
t_args			gethlen(va_list ap, int *f);
t_args			getplen(va_list ap, int *f);
t_args			getolen(va_list ap, int *f);
t_args			getulen(va_list ap, int *f);
t_args			getlulen(va_list ap, int *f);
t_args			getblen(va_list ap, int *f);
t_args			getlolen(va_list ap, int *f);
t_args			getlnlen(va_list ap, int *f);
t_args			get_c_len(va_list ap, int *f);
t_args			getclen(va_list ap, int *f);
t_args			getwslen(va_list ap, int *f);

t_args			minimal_size(char c, va_list ap, int *fl);

char			*save_e(char *s);
char			*ft_subc(char *s, int *j, char c);
char			*save_e(char *s);
int				ft_comp(char *s1, char *s2);
int				ft_e(void);
int				ft_be(void);
char			*getcolor(char *s);

typedef struct	s_si_put
{
	char		flag;
	t_args		(*f)(va_list ap, int *flag);
}				t_si_put;

#endif
