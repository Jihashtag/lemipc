/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:54:28 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 13:17:52 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static unsigned int	countw(char *s, char c)
{
	unsigned int i;
	unsigned int w;

	if (!s)
		return (0);
	w = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			w++;
		while (s[i] == c)
			i++;
		i++;
	}
	return (w + 1);
}

static unsigned int	cword(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

char				**ft_strsplit(char *s, char c)
{
	char	**new;
	int		j;
	int		i;
	int		k;

	new = (char **)malloc(sizeof(char *) * countw(s, c));
	if (!new || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		k = 0;
		while (s[j] == c)
			j++;
		new[i] = (char *)malloc(sizeof(char) * cword(&s[j], c));
		if (!new[i])
			return (NULL);
		while (s[j] && s[j] != c)
			new[i][k++] = s[j++];
		new[i][k] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
