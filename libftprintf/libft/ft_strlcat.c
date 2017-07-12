/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:09:49 by jbert             #+#    #+#             */
/*   Updated: 2015/03/06 13:10:36 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while ((size > 0 && i < size) && j < (size - i - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > 0)
		dst[i + j] = '\0';
	while (size > 0 && src[j])
		j++;
	return (i + j);
}
