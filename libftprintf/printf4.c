/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 22:21:12 by jbert             #+#    #+#             */
/*   Updated: 2015/05/08 22:25:45 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

intmax_t	ft_supzero(void *i, char c, int f)
{
	if (c == 'i' || c == 'd')
	{
		if (f == 1)
			return (*((signed char *)i));
		if (f == 2)
			return (*((short *)i));
		if (f == 3)
			return (*((long int *)i));
		if (f == 4)
			return (*((long long int*)i));
		if (f == 5)
			return (*((intmax_t *)i));
		if (f == 6)
			return (*((long *)i));
		return (*(int *)i);
	}
	if (c == 'D')
		return (*(long int*)i);
	return (0);
}

intmax_t	s1n(va_list ap, int *f)
{
	if (f[8] == 1)
		return (va_arg(ap, int));
	else if (f[8] == 2)
		return (va_arg(ap, int));
	else if (f[8] == 3)
		return (va_arg(ap, long int));
	else if (f[8] == 4)
		return (va_arg(ap, long long int));
	else if (f[8] == 5)
		return (va_arg(ap, intmax_t));
	else if (f[8] == 6)
		return (va_arg(ap, long));
	else
		return (va_arg(ap, int));
}

uintmax_t	ft_usupzero(void *i, int f)
{
	if (f == 1)
		return (*((unsigned char *)i));
	if (f == 2)
		return (*((unsigned short *)i));
	if (f == 3)
		return (*((unsigned long int *)i));
	if (f == 4)
		return (*((unsigned long long int*)i));
	if (f == 5)
		return (*((uintmax_t *)i));
	if (f == 6)
		return (*((unsigned long *)i));
	return (*(unsigned int *)i);
}

intmax_t	s1u(va_list ap, int *f)
{
	if (f[8] == 1)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (f[8] == 2)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (f[8] == 3)
		return (va_arg(ap, unsigned long int));
	else if (f[8] == 4)
		return (va_arg(ap, unsigned long long int));
	else if (f[8] == 5)
		return (va_arg(ap, uintmax_t));
	else if (f[8] == 6)
		return (va_arg(ap, unsigned long));
	return (va_arg(ap, unsigned int));
}
