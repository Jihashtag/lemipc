/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 00:07:54 by jbert             #+#    #+#             */
/*   Updated: 2015/05/10 19:59:58 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

t_si_put		g_size_to_put[] = {
	{'s', getslen},
	{'S', getwslen},
	{'c', getclen},
	{'C', get_c_len},
	{'d', getnlen},
	{'i', getnlen},
	{'D', getlnlen},
	{'x', gethlen},
	{'X', gethlen},
	{'p', getplen},
	{'P', getplen},
	{'b', getblen},
	{'o', getolen},
	{'O', getlolen},
	{'u', getulen},
	{'U', getlulen},
	{0, NULL}
};

t_args		minimal_size(char c, va_list ap, int *fl)
{
	int		i;
	t_args	a;

	i = 0;
	a.arg_size = 1;
	a.args = NULL;
	while (c && g_size_to_put[i].flag != 0)
	{
		if (g_size_to_put[i].flag == c)
			return (g_size_to_put[i].f(ap, fl));
		i++;
	}
	return (a);
}

void		increm(int *j, int *count)
{
	(*j)++;
	(*count)--;
}

void		my_while(char *s, int *j, int *count, int *tb)
{
	fst_inc(s, j, tb);
	if (s[*j] == '.')
	{
		(*j)++;
		(*count)--;
		if (s[(*j)] == '-')
			return ;
		tb[5] = 1;
		tb[6] = ft_atoi(&(s[(*j)]));
		while (ft_isdigit(s[*j]))
			increm(j, count);
	}
	else if (ft_isdigit(s[*j]) && s[*j] != '0')
	{
		tb[7] = ft_atoi(&s[*j]);
		while (ft_isdigit(s[*j]))
			increm(j, count);
	}
	else
		increm(j, count);
}

int			*ft_flag(char *s, int *j, int *count)
{
	int		*tb;

	if (!(tb = (int *)malloc(sizeof(int) * 9)))
		return (NULL);
	ft_bzero(tb, sizeof(int) * 9);
	while (s[*j] && (s[*j] == ' ' || s[*j] == '#' || ft_isdigit(s[*j]) || \
				s[*j] == '+' || s[*j] == '-' || s[*j] == '.' || \
				s[*j] == 'h' || s[*j] == 'l' || s[*j] == 'j' || s[*j] == 'z'))
		my_while(s, j, count, tb);
	if (s[*j] == 'E')
		save_e(ft_subc(s, j, '%'));
	if (s[*j] == 'e')
		save_e(ft_subc(s, j, '%'));
	return (tb);
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		j;
	int		count;
	int		*f;

	va_start(ap, format);
	count = 0;
	j = 0;
	while (format[j])
	{
		if (format[j] == '%' && ++j)
		{
			count--;
			f = ft_flag(format, &j, &count);
			if (format[j])
				count += ft_treatment(format, j++, ap, f) - 1;
			if (f)
				free(f);
		}
		else
			j += write(1, &format[j], 1);
	}
	va_end(ap);
	return (count + j);
}
