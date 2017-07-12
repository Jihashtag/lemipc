/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 21:51:45 by jbert             #+#    #+#             */
/*   Updated: 2015/05/10 18:07:34 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

void		*memdup(void *or, unsigned long int n)
{
	void	*new;

	new = malloc(n);
	ft_bzero(new, n);
	while (--n)
		((char *)new)[n] = ((char *)or)[n];
	((char *)new)[0] = ((char *)or)[0];
	return (new);
}

int			ft_wstrlen(wchar_t *wstr)
{
	int	i;

	i = 0;
	if (!wstr)
		return (6);
	while (*wstr)
	{
		if (*wstr <= 0x7F)
			i += 1;
		else if (*wstr <= 0x7FF)
			i += 2;
		else if (*wstr <= 0xFFFF)
			i += 3;
		else if (*wstr <= 0x10FFFF)
			i += 4;
		wstr++;
	}
	return (i);
}

int			ft_putwchar(wchar_t c)
{
	int	i;

	i = 0;
	if (c <= 0x7F)
		i += ft_putchar(c);
	else if (c <= 0x7FF)
	{
		i += ft_putchar((c >> 6) + 0xC0);
		i += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		i += ft_putchar((c >> 12) + 0xE0);
		i += ft_putchar(((c >> 6) & 0x3F) + 0x80);
		i += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		i += ft_putchar((c >> 18) + 0xF0);
		i += ft_putchar(((c >> 12) & 0x3F) + 0x80);
		i += ft_putchar(((c >> 6) & 0x3F) + 0x80);
		i += ft_putchar((c & 0x3F) + 0x80);
	}
	return (i);
}

int			ft_putwstr(wchar_t *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s && *s)
	{
		i += ft_putwchar(*s);
		s++;
	}
	return (i);
}

int			write_c(void *arg, char c, int f)
{
	if (c == 'C' || (c == 'c' && f == 3))
		return (ft_putwchar(*(wchar_t *)arg));
	if (c == 'c')
		return (ft_putchar(*(char *)arg));
	return (0);
}
