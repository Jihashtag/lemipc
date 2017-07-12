/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:33:30 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 14:22:41 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (dst > src || &(((char *)dst)[i]) < &(((char *)src)[0]))
			((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
