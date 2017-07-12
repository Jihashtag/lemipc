/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 20:03:50 by jbert             #+#    #+#             */
/*   Updated: 2015/05/10 20:04:30 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char		*getcolor(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	while (!ft_isalpha(s[i]))
		i++;
	j = 0;
	while (ft_isalpha(s[i]))
	{
		i++;
		j++;
	}
	s2 = memdup(&(s[i - j]), j);
	s2[j] = '\0';
	return (s2);
}
