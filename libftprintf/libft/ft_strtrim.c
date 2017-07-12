/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 11:08:52 by jbert             #+#    #+#             */
/*   Updated: 2015/03/05 13:28:13 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		nowhite(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	j--;
	while (j > 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (j == 0)
		return (0);
	return (j - i + 1);
}

char			*ft_strtrim(char *s)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!s || s == NULL)
		return (NULL);
	k = nowhite(s);
	new = (char *)malloc(sizeof(char) * (k + 1));
	if (!new && k > 0)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = 0;
	while (j < k && s[i + j])
	{
		new[j] = s[i + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
