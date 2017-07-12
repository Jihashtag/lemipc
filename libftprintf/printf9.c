/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:59:34 by jbert             #+#    #+#             */
/*   Updated: 2015/05/10 20:00:30 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char		*ft_subc(char *s, int *j, char c)
{
	int		i;

	i = 1;
	(*j)++;
	while (s[*j] && s[*j] != c)
	{
		(*j)++;
		i++;
	}
	if (s[*j])
	{
		(*j)++;
		return (memdup(&(s[*j - i]), i));
	}
	else
		return (NULL);
}

char		*save_e(char *s)
{
	static char *save = NULL;

	if (s)
	{
		save = s;
		return (NULL);
	}
	s = save;
	save = NULL;
	return (s);
}

int			ft_comp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	free(s1);
	return (1);
}

int			ft_e(void)
{
	char	*s;
	char	*s2;

	s = save_e(NULL);
	s2 = getcolor(s);
	free(s);
	if (ft_comp(s2, "black"))
		return (ft_putstr("\033[30m\0"));
	if (ft_comp(s2, "red"))
		return (ft_putstr("\033[31m\0"));
	if (ft_comp(s2, "green"))
		return (ft_putstr("\033[32m\0"));
	if (ft_comp(s2, "yellow"))
		return (ft_putstr("\033[33m\0"));
	if (ft_comp(s2, "blue"))
		return (ft_putstr("\033[34m\0"));
	if (ft_comp(s2, "purple"))
		return (ft_putstr("\033[35m\0"));
	if (ft_comp(s2, "cyan"))
		return (ft_putstr("\033[36m\0"));
	if (ft_comp(s2, "grey"))
		return (ft_putstr("\033[37m\0"));
	return (ft_putstr("\033[0m\0"));
}

int			ft_be(void)
{
	char	*s;
	char	*s2;

	s = save_e(NULL);
	s2 = getcolor(s);
	free(s);
	if (ft_comp(s2, "black"))
		return (ft_putstr("\033[40m\0"));
	if (ft_comp(s2, "red"))
		return (ft_putstr("\033[41m\0"));
	if (ft_comp(s2, "green"))
		return (ft_putstr("\033[42m\0"));
	if (ft_comp(s2, "yellow"))
		return (ft_putstr("\033[43m\0"));
	if (ft_comp(s2, "blue"))
		return (ft_putstr("\033[44m\0"));
	if (ft_comp(s2, "purple"))
		return (ft_putstr("\033[45m\0"));
	if (ft_comp(s2, "cyan"))
		return (ft_putstr("\033[46m\0"));
	if (ft_comp(s2, "grey"))
		return (ft_putstr("\033[47m\0"));
	return (ft_putstr("\033[0m\0"));
}
