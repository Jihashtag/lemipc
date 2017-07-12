/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:02:04 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:02:56 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	get_to_ennemy(int *ennemy, char *map, int player)
{
	int		my_int[3];

	my_int[0] = ennemy[1] / (S + 1);
	my_int[1] = (ennemy[0] % (S + 1)) - (ennemy[2] % (S + 1));
	my_int[2] = ennemy[0] > ennemy[2] ? 1 : -1;
	if (my_int[1] < 0)
		my_int[1] = -my_int[1];
	map[ennemy[2]] = '#';
	if ((my_int[2] * (S + 1) + ennemy[2]) <= (S * (S + 1)) && \
			(my_int[0] >= my_int[1] || (my_int[1] < S && \
			ennemy[0] / (S + 1) != ennemy[2] / (S + 1))) && \
			map[(S + 1) * my_int[2] + ennemy[2]] == '#')
	{
		map[ennemy[2] + (S + 1) * my_int[2]] = player + '0';
		if (D)
			ft_printf("[%d][Vert1]\n", my_int[2]);
		return ;
	}
	else if (norm_get_to_ennemy(ennemy, map, player, my_int))
		return ;
	map[ennemy[2]] = player + '0';
	if (D)
		ft_printf("I skip my turn...\n");
}
