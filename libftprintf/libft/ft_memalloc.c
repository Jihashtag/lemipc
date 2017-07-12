/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:58:45 by jbert             #+#    #+#             */
/*   Updated: 2015/03/03 13:03:41 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void			*new;
	unsigned int	i;

	new = malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)new)[i] = 0;
		i += sizeof(char);
	}
	return (new);
}
