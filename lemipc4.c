/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:58:24 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:37:21 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			found_player(char *map, int *ennemy, int *team, int i)
{
	int		player;

	player = ennemy[3];
	ennemy[2] = i;
	if (loss(map, ennemy[2], team, team[player - 1]))
	{
		ft_printf("[Player : %d]Sorry, I lose\n", player);
		map[ennemy[2]] = '#';
		return (1);
	}
	if (ennemy[1] != (S * (S + 1)))
		ennemy[1] = ennemy[2] - ennemy[1];
	return (0);
}

int			*get_nearest_ennemy(char *map, int player, int *team)
{
	static int	ennemy[4] = {-1, -1, 0, 0};
	int			i;
	int			new;

	i = -1;
	ennemy[2] = -1;
	ennemy[0] = -1;
	ennemy[3] = player;
	ennemy[1] = S * (S + 1);
	new = -1;
	while (map[++i])
	{
		if (map[i] - '0' == player && found_player(map, ennemy, team, i))
			return (NULL);
		if (map[i] != '#' && map[i] != '\n' && \
				team[(map[i] - '0') - 1] != team[player - 1])
		{
			new = ennemy[2] > i ? ennemy[2] - i : i - ennemy[2];
			if ((new < ennemy[1] || ennemy[2] == -1) && (ennemy[0] = i) > 0)
				ennemy[1] = new;
		}
	}
	if (ennemy[2] < 0 && ft_printf("I'm not on the map [%s]\n", map))
		return (NULL);
	return (ennemy);
}

void		norm_send_ennemy(struct s_msgg *buf, int *i, int *e)
{
	buf->mtype = 1;
	buf->pos = e[0];
	buf->dist = e[1];
	*i = -1;
}

int			*send_ennemy(int *e, int player, int *t, int cp)
{
	struct s_msgg		buf;
	int					ldist;
	int					lpos;
	int					i;
	int					msgid;

	ldist = S * (S + 1);
	if (D)
		ft_printf("Nearest ennemy is in [%d] at [%d] of me [%d]\n", \
				e[0], e[1], e[2]);
	msgid = msgget(MSGK + player - 1, 0666);
	while (msgrcv(msgid, &buf, MSGS, 1, IPC_NOWAIT) > 0)
		if (buf.dist < ldist && (ldist = buf.dist))
			lpos = buf.pos;
	norm_send_ennemy(&buf, &i, e);
	while (++i < cp)
		if (i != player - 1 && t[i] == t[player - 1] && \
				(msgid = msgget(MSGK + i, 0666)) && \
				msgsnd(msgid, &buf, MSGS, 0) < 0 && D && \
				ft_putstr_fd("Error at sending MSG to : ", 2) && ft_putnbr(i))
			perror("\n");
	if (ldist < e[1] && (e[0] = lpos) && \
			(e[1] = ldist) && D)
		ft_printf("Going after [%d] at [%d] of partner\n", e[0], e[1]);
	return (e);
}

int			norm_get_to_ennemy(int *e, char *map, int player, int *mi)
{
	if (map[e[2] + mi[2]] == '#' && (map[e[2] + mi[2]] = player + '0') && \
			((D && ft_printf("[%d][Hor1]\n", mi[2])) || !D))
		return (1);
	else if ((e[2] - (mi[2] * (S + 1))) <= (S * (S + 1)) && \
			map[e[2] - ((S + 1) * mi[2])] == '#')
	{
		map[e[2] - ((S + 1) * mi[2])] = player + '0';
		if ((D && ft_printf("[%d][Vert2]\n", mi[2])) || !D)
			return (1);
	}
	else if (map[e[2] - mi[2]] == '#')
	{
		map[e[2] - mi[2]] = player + '0';
		if ((D && ft_printf("[%d][Hor2]\n", mi[2])) || !D)
			return (1);
	}
	else if (e[2] > S + 1 && e[2] + (mi[2] * (S + 1)) < (S * (S + 1))\
			&& map[e[2] + (mi[2] * (S + 1))] == '#')
	{
		map[e[2] + (S + 1) * mi[2]] = player + '0';
		if ((D && ft_printf("[%d][Vert3]\n", mi[2])) || !D)
			return (1);
	}
	return (0);
}
