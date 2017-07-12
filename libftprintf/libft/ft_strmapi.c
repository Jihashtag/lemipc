/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:30:00 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 13:05:19 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char				*new;
	unsigned int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
