/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:31:38 by jbert             #+#    #+#             */
/*   Updated: 2015/03/03 13:50:57 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		hm(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static int		fillstring(char *s, int i, int n)
{
	if (n < 10)
	{
		s[i] = n + '0';
		return (i + 1);
	}
	i = fillstring(s, i, n / 10);
	i = fillstring(s, i, n % 10);
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * hm(n));
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		ret[i] = '-';
		i++;
	}
	i = fillstring(ret, i, n);
	ret[i] = '\0';
	return (ret);
}
