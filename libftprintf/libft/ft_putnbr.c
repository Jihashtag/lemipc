/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 09:46:42 by jbert             #+#    #+#             */
/*   Updated: 2015/04/04 13:11:45 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <inttypes.h>
#include <limits.h>

static int	ft_put(int i)
{
	char	c;

	c = i + '0';
	return (write(1, &c, 1));
}

int			ft_putnbr(intmax_t n)
{
	int		i;

	i = 0;
	if (n == LONG_MIN)
		return (write(1, "-9223372036854775808", 20));
	if (n < 0)
	{
		i = write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
		return (ft_put(n) + i);
	i += ft_putnbr(n / 10);
	return (ft_putnbr(n % 10) + i);
}
