/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 22:31:39 by jbert             #+#    #+#             */
/*   Updated: 2015/05/08 22:32:06 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

t_args		getnlen(va_list ap, int *f)
{
	intmax_t	i;
	intmax_t	s1;
	t_args		a;

	s1 = s1n(ap, f);
	a.args = memdup(&s1, sizeof(s1));
	i = (ft_supzero(a.args, 'd', f[8]) >= 0) ? 1 : -1;
	a.arg_size = (ft_supzero(a.args, 'd', f[8]) >= 0) ? 1 : 2;
	while ((i > 0 && ((i * 10) - 1) < ft_supzero(a.args, 'd', f[8])) || \
			(i < 0 && ((i * 10) - 1) > ft_supzero(a.args, 'd', f[8])))
	{
		i *= 10;
		a.arg_size++;
	}
	return (a);
}

t_args		getulen(va_list ap, int *f)
{
	uintmax_t		i;
	uintmax_t		s1;
	t_args			a;

	s1 = s1u(ap, f);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 1;
	while (((i * 10) - 1) < ft_usupzero(a.args, f[8]))
	{
		i *= 10;
		a.arg_size++;
	}
	return (a);
}

t_args		getlulen(va_list ap, int *f)
{
	unsigned long long	i;
	unsigned long int	s1;
	t_args				a;

	(void)f;
	s1 = va_arg(ap, unsigned long int);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 1;
	while (((i * 10) - 1) < *((unsigned long int *)a.args))
	{
		i *= 10;
		a.arg_size++;
	}
	return (a);
}

t_args		gethlen(va_list ap, int *f)
{
	uintmax_t		i;
	uintmax_t		s1;
	t_args			a;

	s1 = s1u(ap, f);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = (f[1] > 0) ? 3 : 1;
	while (((i * 16) - 1) < ft_usupzero(a.args, f[8]))
	{
		i *= 16;
		a.arg_size++;
	}
	return (a);
}

t_args		getplen(va_list ap, int *f)
{
	unsigned long long	i;
	unsigned long int	s1;
	t_args				a;

	(void)f;
	s1 = va_arg(ap, unsigned long int);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 3;
	while (((i * 16) - 1) < *((unsigned long int *)a.args))
	{
		i *= 16;
		a.arg_size++;
	}
	return (a);
}
