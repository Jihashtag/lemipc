/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:25:03 by jbert             #+#    #+#             */
/*   Updated: 2015/05/09 17:25:43 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

t_args		getolen(va_list ap, int *f)
{
	uintmax_t		i;
	uintmax_t		s1;
	t_args			a;

	s1 = s1u(ap, f);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 1 + f[1];
	while (((i * 8) - 1) < ft_usupzero(a.args, f[8]))
	{
		i *= 8;
		a.arg_size++;
	}
	return (a);
}

t_args		getblen(va_list ap, int *f)
{
	unsigned long int	i;
	unsigned int		s1;
	t_args				a;

	(void)f;
	s1 = va_arg(ap, unsigned int);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 1;
	while (((i * 2) - 1) < *((unsigned int *)a.args))
	{
		i *= 2;
		a.arg_size++;
	}
	return (a);
}

t_args		getlolen(va_list ap, int *f)
{
	unsigned long long	i;
	unsigned long int	s1;
	t_args				a;

	(void)f;
	s1 = va_arg(ap, unsigned long int);
	a.args = memdup(&s1, sizeof(s1));
	i = 1;
	a.arg_size = 1;
	while (((i * 8) - 1) < *((unsigned long int *)a.args))
	{
		i *= 8;
		a.arg_size++;
	}
	return (a);
}

t_args		getlnlen(va_list ap, int *f)
{
	long double	i;
	long int	s1;
	t_args		a;

	(void)f;
	s1 = va_arg(ap, long int);
	a.args = memdup(&s1, sizeof(s1));
	i = (s1 >= 0) ? 1 : -1;
	a.arg_size = (s1 >= 0) ? 1 : 2;
	while ((i > 0 && ((i * 10) - 1) < *((long int *)a.args)) || \
			(i < 0 && ((i * 10) + 1) > *((long int *)a.args)))
	{
		i *= 10;
		a.arg_size++;
	}
	return (a);
}
