/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 11:35:41 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 13:15:51 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while ((s1 && s1[i - j]) || (s2 && s2[j]))
	{
		if (s1 && s1[i - j])
			new[i] = s1[i];
		else if (s2)
			new[i] = s2[j++];
		i++;
	}
	new[i] = '\0';
	return (new);
}
