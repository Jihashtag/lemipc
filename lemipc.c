/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:03:53 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:36:08 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

size_t		norm_player(t_shst **info, char *av, struct s_ipcs *ipcs, int k)
{
	ipcs->semopst = malloc(sizeof(struct sembuf));
	ipcs->shm = shmget(k, 0, 0600);
	if (ipcs->shm == -1)
	{
		perror("shmget : ");
		exit(1);
	}
	ipcs->sem = semget(k, 0, 0600);
	if (ipcs->sem == -1)
	{
		perror("semget : ");
		exit(1);
	}
	ipcs->semopst[0].sem_num = 0;
	ipcs->semopst[0].sem_op = -1;
	semop(ipcs->sem, ipcs->semopst, 1);
	*info = shmat(ipcs->shm, NULL, 0);
	ipcs->semopst[0].sem_num = 0;
	ipcs->semopst[0].sem_op = 1;
	(*info)->t[(*info)->cp] = av[0];
	(*info)->cp++;
	(*info)->ret = 1;
	(*info)->rq = 0;
	return ((*info)->cp);
}

void		player_exit(t_shst *info, struct s_ipcs ipcs)
{
	if (info->rqtype == T)
		ft_putstr("J'ai (probablement) Gagne !!!\n");
	info->ret = 1;
	info->rq = 0;
	shmdt(info);
	semop(ipcs.sem, ipcs.semopst, 1);
	free(ipcs.semopst);
	exit(0);
}

t_shst		*player_norm(t_shst *info, struct s_ipcs ipcs)
{
	shmdt(info);
	semop(ipcs.sem, ipcs.semopst, 1);
	ipcs.semopst[0].sem_num = 0;
	ipcs.semopst[0].sem_op = -1;
	semop(ipcs.sem, ipcs.semopst, 1);
	info = shmat(ipcs.shm, NULL, 0);
	ipcs.semopst[0].sem_num = 0;
	ipcs.semopst[0].sem_op = 1;
	return (info);
}

void		player(int k, char *av)
{
	struct s_ipcs	ipcs;
	t_shst			*info;
	size_t			playernb;
	int				*ennemy;

	playernb = norm_player(&info, av, &ipcs, k);
	while (1)
	{
		while (info->rqtype != PT || \
				(info->rqtype == PT && info->rq != playernb))
		{
			info = player_norm(info, ipcs);
			if (info->rqtype == T && info->rq == playernb)
				break ;
		}
		if (info->rqtype == T)
			player_exit(info, ipcs);
		ennemy = get_nearest_ennemy(info->map, playernb, info->t);
		if (!ennemy && (info->t[playernb - 1] = 0) == 0 && info->nbp--)
			player_exit(info, ipcs);
		ennemy = send_ennemy(ennemy, playernb, info->t, info->cp);
		get_to_ennemy(ennemy, info->map, playernb);
		info->ret = 1;
		info->rq = 0;
	}
}

int			main(int ac, char **av)
{
	key_t	key;

	key = ftok("lemipc", 42);
	if (ac == 3)
		creator(key, av);
	else if (ac > 2 || ac < 2)
	{
		ft_putstr_fd("Too many/few arguments\n", 2);
		help();
	}
	else if (ac == 2)
		player(key, av[1]);
	return (0);
}
