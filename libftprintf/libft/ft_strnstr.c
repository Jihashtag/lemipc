/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:10:48 by jbert             #+#    #+#             */
/*   Updated: 2016/01/02 17:21:12 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
