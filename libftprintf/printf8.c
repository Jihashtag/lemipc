/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 18:58:52 by jbert             #+#    #+#             */
/*   Updated: 2015/05/10 20:04:33 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int			ft_putsp(int no_w, int *f, int j)
{
	int		i;
	char	w;

	i = 0;
	if (f[3])
		no_w++;
	w = (f[2] > 0 && !f[5] && !f[4]) ? '0' : ' ';
	while (((f[4] && j) || (!f[4] && !j)) && i < (f[7] - no_w))
	{
		if (ft_putchar(w) == 0)
			return (i);
		i++;
	}
	return (i);
}

int			ft_0x(char c, int *f, t_args args)
{
	if ((c == 'p' || (f[1] && c == 'x' && \
					ft_usupzero(args.args, f[8]) != 0)) && f[2])
		return (ft_putstr("0x"));
	else if ((c == 'P' || (f[1] && c == 'X' && \
					ft_usupzero(args.args, f[8]) != 0)) && f[2])
		return (ft_putstr("0X"));
	return (0);
}

int			ft_spec(t_args args, char c, int *f)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (ft_s_c(c, args.args, f[8]));
	else if (c == 'd' || c == 'i')
		return (ft_d_i(args.args, f[8]));
	else if (c == 'p' || c == 'x' || c == 'X' || c == 'P')
		return (write_base(args.args, c, f));
	else if (c == 'o' || c == 'O')
		return (ft_o(args.args, f, c));
	else if (c == 'u')
		return (ft_base(args.args, f[8], "0123456789"));
	else if (c == 'U')
		return (ft_putbase(*(unsigned long int *)args.args, "0123456789"));
	else if (c == 'D')
		return (ft_putnbr(*((long int *)args.args)));
	else if (c == 'b')
		return (ft_putbase(*(unsigned int *)args.args, "01"));
	else if (c == 'e')
		return (ft_e());
	else if (c == 'E')
		return (ft_be());
	return (ft_putchar(c));
}

int			ft_treatment(char *s, int j, va_list ap, int *f)
{
	t_args	args;
	int		ret;

	args = minimal_size(s[j], ap, f);
	if (f[3] && ((ISINT(s[j]) && ft_supzero(args.args, s[j], f[8]) < 0) || \
				!ISINT(s[j])))
		f[3] = 0;
	ret = 0;
	if (f[0] && !f[3] && ISINT(s[j]) && ft_supzero(args.args, s[j], f[8]) >= 0)
	{
		args.arg_size += ft_putchar(' ');
		ret = 1;
	}
	ret += ft_0x(s[j], f, args);
	ret += (f[3] > 0 && f[2]) ? ft_putchar('+') : 0;
	ret += ft_putsp(args.arg_size, f, 0);
	ret += (f[3] > 0 && !f[2]) ? ft_putchar('+') : 0;
	ret += ft_spec(args, s[j], f);
	if (s[j] == 'd' || s[j] == 'i' || s[j] == 'p' || s[j] == 'x' || \
			s[j] == 'X' || s[j] == 'c' || s[j] == 'C' || s[j] == 'P' || \
			s[j] == 'b' || s[j] == 'o' || s[j] == 'O' || s[j] == 'D' || \
			s[j] == 'u' || s[j] == 'U')
		free(args.args);
	ret += ft_putsp(args.arg_size, f, 1);
	return (ret);
}

void		fst_inc(char *s, int *j, int *tb)
{
	if (s[*j] == ' ')
		tb[0]++;
	if (s[*j] == '#')
		tb[1]++;
	if (s[*j] == '0')
		tb[2]++;
	if (s[*j] == '+')
		tb[3]++;
	if (s[*j] == '-')
		tb[4]++;
	if (s[*j] == 'h' && s[(*j) + 1] == 'h')
		tb[8] = 1;
	if (s[*j] == 'h' && s[(*j) + 1] != 'h' && s[(*j) - 1] != 'h')
		tb[8] = 2;
	if (s[*j] == 'l' && s[(*j) + 1] != 'l' && s[(*j) - 1] != 'l')
		tb[8] = 3;
	if (s[*j] == 'l' && s[(*j) + 1] == 'l')
		tb[8] = 4;
	if (s[*j] == 'j')
		tb[8] = 5;
	if (s[*j] == 'z')
		tb[8] = 6;
}
