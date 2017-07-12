/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:30:00 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 13:05:05 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	return (new);
}
