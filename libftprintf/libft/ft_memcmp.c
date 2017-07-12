/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:39:30 by jbert             #+#    #+#             */
/*   Updated: 2015/03/07 11:25:23 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned int	i;
	int				f;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
		{
			f = (unsigned char)((char *)s1)[i] - (unsigned char)((char *)s2)[i];
			return (f);
		}
		i++;
	}
	return (0);
}
