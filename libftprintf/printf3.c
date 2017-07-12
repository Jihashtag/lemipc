/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 22:05:34 by jbert             #+#    #+#             */
/*   Updated: 2015/05/08 22:06:13 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int			ft_putbase(uintmax_t nb, char *s)
{
	unsigned int	b;
	int				i;

	i = 0;
	b = ft_strlen(s);
	if (nb < b)
		return (ft_putchar(s[nb]));
	i += ft_putbase(nb / b, s);
	i += ft_putbase(nb % b, s);
	return (i);
}

t_args		get_c_len(va_list ap, int *f)
{
	t_args	a;
	wchar_t	c;

	(void)f;
	c = va_arg(ap, wchar_t);
	a.args = memdup(&c, sizeof(c));
	if (c <= 0x7F)
		a.arg_size = 1;
	else if (c <= 0x7FF)
		a.arg_size = 2;
	else if (c <= 0xFFFF)
		a.arg_size = 3;
	else if (c <= 0x10FFFF)
		a.arg_size = 4;
	return (a);
}

t_args		getclen(va_list ap, int *f)
{
	t_args	a;
	char	c;

	if (f[8] == 3)
		return (get_c_len(ap, f));
	c = va_arg(ap, int);
	a.args = memdup(&c, sizeof(c));
	a.arg_size = 1;
	return (a);
}

t_args		getwslen(va_list ap, int *f)
{
	t_args	a;

	(void)f;
	a.args = va_arg(ap, wchar_t *);
	a.arg_size = ft_wstrlen((wchar_t *)a.args);
	return (a);
}

t_args		getslen(va_list ap, int *f)
{
	t_args	a;

	if (f[8] == 3)
		return (getwslen(ap, f));
	a.args = va_arg(ap, char *);
	a.arg_size = ft_strlen((char *)a.args);
	return (a);
}
