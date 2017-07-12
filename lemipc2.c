/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:40:37 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:36:55 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		end(struct s_ipcs ipcs, int n)
{
	int	i;
	int	mid;

	semctl(ipcs.sem, 0, IPC_RMID);
	shmctl(ipcs.shm, IPC_RMID, 0);
	free(ipcs.semopst);
	i = 0;
	while (i < n)
	{
		mid = msgget(MSGK + i, 0666);
		msgctl(mid, IPC_RMID, 0);
		i++;
	}
}

void		sub_signh(t_shst *info, struct s_ipcs *ipcs, int cp)
{
	int			i;

	i = 1;
	while (i < cp)
	{
		if (info->t[i] == 0)
		{
			i++;
			continue ;
		}
		info->rq = i + 1;
		info->ret = 0;
		info->rqtype = T;
		ipcs->semopst[0].sem_num = 0;
		ipcs->semopst[0].sem_op = 1;
		shmdt(info);
		semop(ipcs->sem, ipcs->semopst, 1);
		ipcs->semopst[0].sem_num = 0;
		ipcs->semopst[0].sem_op = -1;
		semop(ipcs->sem, ipcs->semopst, 1);
		info = shmat(ipcs->shm, NULL, 0);
		if (info->ret)
			i++;
	}
}

void		signal_handler(int sig)
{
	struct s_ipcs	*ipcs;
	t_shst			*info;

	ipcs = get_ipcs(NULL);
	ipcs->semopst[0].sem_num = 0;
	ipcs->semopst[0].sem_op = -1;
	semop(ipcs->sem, ipcs->semopst, 1);
	info = shmat(ipcs->shm, NULL, 0);
	sub_signh(info, ipcs, get_cp(0));
	end(*ipcs, get_cp(0));
	exit(sig);
}

void		put_rand(char c, char *map)
{
	int	i;

	i = rand() + (int)map;
	if (i > S * (S + 1))
		i = i % (S * (S + 1));
	if ((i - 1) % S == 0)
		return (put_rand(c, map));
	if (map[i] != '#')
		return (put_rand(c, map));
	map[i] = c;
}

int			nb_team(int *tb, int size)
{
	int		i;
	int		lt;

	i = 0;
	lt = 0;
	while (i < size)
	{
		if (lt != 0 && tb[i] != 0 && lt != tb[i])
			return (2);
		if (tb[i] != 0)
			lt = tb[i];
		i++;
	}
	return (0);
}
