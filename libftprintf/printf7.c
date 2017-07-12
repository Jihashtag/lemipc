/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 18:51:07 by jbert             #+#    #+#             */
/*   Updated: 2015/05/09 18:52:34 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int			ft_s_c(char c, void *arg, int f)
{
	if (c == 'S' || (c == 's' && f == 3))
		return (ft_putwstr((wchar_t *)arg));
	else if (c == 's')
		return (ft_putstr((char *)arg));
	else if (c == 'c' || c == 'C')
		return (write_c(arg, c, f));
	return (0);
}

int			ft_o(void *arg, int *f, char c)
{
	int	i;

	i = 0;
	if (f[1] && *(int *)arg != 0)
		i = ft_putchar('0');
	if (c == 'o')
		return (ft_base(arg, f[8], "01234567") + i);
	else if (c == 'O')
		return (ft_putbase(*(unsigned long int *)arg, "01234567") + i);
	return (i);
}

int			ft_d_i(void *arg, int f)
{
	if (f == 1)
		return (ft_putnbr(*((signed char *)arg)));
	if (f == 2)
		return (ft_putnbr(*((short *)arg)));
	if (f == 3)
		return (ft_putnbr(*((long int *)arg)));
	if (f == 4)
		return (ft_putnbr(*((long long int*)arg)));
	if (f == 5)
		return (ft_putnbr(*((intmax_t *)arg)));
	if (f == 6)
		return (ft_putnbr(*((long *)arg)));
	return (ft_putnbr(*((int *)arg)));
}

int			ft_base(void *arg, int f, char *s)
{
	if (f == 1)
		return (ft_putbase(*((unsigned char *)arg), s));
	if (f == 2)
		return (ft_putbase(*((unsigned short *)arg), s));
	if (f == 3)
		return (ft_putbase(*((unsigned long int *)arg), s));
	if (f == 4)
		return (ft_putbase(*((unsigned long long int *)arg), s));
	if (f == 5)
		return (ft_putbase(*((uintmax_t *)arg), s));
	if (f == 6)
		return (ft_putbase(*((long *)arg), s));
	return (ft_putbase(*((unsigned int *)arg), s));
}

int			write_base(void *arg, char w, int *f)
{
	int	i;

	i = 0;
	if ((w == 'p' || (f[1] && w == 'x' && \
					ft_usupzero(arg, f[8]) != 0)) && !f[2])
		i += ft_putstr("0x");
	else if ((w == 'P' || (f[1] && w == 'X' && \
					ft_usupzero(arg, f[8]) != 0)) && !f[2])
		i += ft_putstr("0X");
	if (w == 'x')
		i += ft_base(arg, f[8], "0123456789abcdef");
	else if (w == 'X')
		i += ft_base(arg, f[8], "0123456789ABCDEF");
	else if (w == 'p')
		i += ft_putbase(*((unsigned long int *)arg), "0123456789abcdef");
	else if (w == 'P')
		i += ft_putbase(*((unsigned long int *)arg), "0123456789ABCDEF");
	return (i);
}
