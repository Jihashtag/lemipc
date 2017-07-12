/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 09:46:42 by jbert             #+#    #+#             */
/*   Updated: 2015/04/04 13:12:07 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_put(int i, int fd)
{
	char c;

	c = i + '0';
	return (write(fd, &c, 1));
}

int				ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
		return (ft_put(n, fd));
	ft_putnbr_fd(n / 10, fd);
	return (ft_putnbr_fd(n % 10, fd));
}
