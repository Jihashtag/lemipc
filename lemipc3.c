/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:56:23 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:37:11 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_shst		*play_norm(t_shst *info, struct s_ipcs ipcs, int rq, int rqtype)
{
	info->rqtype = rqtype;
	info->rq = rq;
	info->ret = 0;
	shmdt(info);
	ipcs.semopst[0].sem_num = 0;
	ipcs.semopst[0].sem_op = 1;
	semop(ipcs.sem, ipcs.semopst, 1);
	ipcs.semopst[0].sem_num = 0;
	ipcs.semopst[0].sem_op = -1;
	semop(ipcs.sem, ipcs.semopst, 1);
	info = shmat(ipcs.shm, NULL, 0);
	return (info);
}

t_shst		*play_norm2(t_shst *info, struct s_ipcs ipcs, int i)
{
	int	cp;
	int	*ennemy;

	if (info->t[0] != 0)
	{
		ennemy = get_nearest_ennemy(info->map, 1, info->t);
		if (!ennemy && (info->t[0] = 0) == 0)
			info->nbp--;
		else if ((ennemy = send_ennemy(ennemy, 1, info->t, info->cp)))
			get_to_ennemy(ennemy, info->map, 1);
	}
	cp = 1;
	while (cp < info->cp)
	{
		if (info->t[cp] == 0 && cp++)
			continue ;
		info = play_norm(info, ipcs, cp + 1, PT);
		cp = info->ret ? cp + 1 : cp;
		get_cp(info->cp);
	}
	ft_printf("End of turn [%d] : \"\n%s\"\n", i, info->map);
	return (info);
}

void		play_fct(struct s_shst *info, struct s_ipcs ipcs)
{
	size_t		cp;
	int			msgflg;
	int			i;
	int			*ennemy;

	msgflg = IPC_CREAT | 0666;
	if ((cp = 1) && msgget(MSGK, msgflg) < 0)
		ft_putendl_fd("Couldn't create msg", 2);
	while (info->cp < info->nbp)
	{
		info = play_norm(info, ipcs, cp, NP);
		if (info->ret && (msgget(MSGK + cp, msgflg) < 0))
			ft_putendl_fd("Couldn't create msg", 2);
		cp = info->ret ? get_cp(info->cp) + 1 : get_cp(info->cp);
	}
	cp = -1;
	while (++cp < info->cp)
		put_rand(cp + 1 + '0', info->map);
	i = -1;
	while (++i >= 0 && info->nbp > 2 && nb_team(info->t, info->cp))
		info = play_norm2(info, ipcs, i);
	ft_printf("End of game (Turn[%d]) : \"\n%s\"\n", i, info->map);
	signal_handler(0);
}

void		creator(key_t k, char **av)
{
	int				nbp;
	t_shst			*info;
	size_t			info_len;
	size_t			i;
	struct s_ipcs	ipcs;

	i = -1;
	while (++i < 31)
		signal(i, &signal_handler);
	if ((nbp = ft_atoi(av[1])) < 1)
		help();
	get_ipcs(&ipcs);
	info_len = sizeof(struct s_shst) + (sizeof(int) * nbp);
	info = init(k, NULL, info_len, nbp, &ipcs);
	ft_memset(info->map, '#', S * (S + 1));
	i = 0;
	while (++i <= S)
		info->map[i * (S + 1) - 1] = '\n';
	info->map[S * (S + 1)] = 0;
	info->nbp = nbp;
	info->cp = 1;
	ft_memset(info->t, 0, nbp * sizeof(int));
	info->t[0] = av[2][0];
	play_fct(info, ipcs);
	end(ipcs, nbp);
}

int			loss(char *map, int me, int *team, int mteam)
{
	int		inc;
	int		num;

	inc = S + 1;
	num = 0;
	if (map[me + 1] != '#' && map[me + 1] != '\n' && \
			team[map[me + 1] - '0' - 1] != mteam)
		num++;
	if (me >= 1 && map[me - 1] != '#' && map[me - 1] != '\n' && \
			team[map[me - 1] - '0' - 1] != mteam)
		num++;
	if (me >= inc && map[me - inc] != '#' && \
			team[map[me - inc] - '0' - 1] != mteam)
		num++;
	if (num && me + inc < (inc * inc - inc) && \
			map[me + inc] != '#' && team[map[me + inc] - '0' - 1] != mteam)
		num++;
	if (num < 2)
		return (0);
	return (1);
}
