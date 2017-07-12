/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:33:54 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:42:45 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void			help(void)
{
	ft_putstr_fd("Usage : ./lemipc <nb_player> <int team>\
				#to create map and launch game\n\
			./lemipc <int team> #to join game\n", 2);
	exit(1);
}

struct s_ipcs	*get_ipcs( struct s_ipcs *ipc)
{
	static struct s_ipcs *ip = NULL;

	if (ipc)
		ip = ipc;
	return (ip);
}

size_t			get_cp(size_t cp)
{
	static size_t i = 0;

	if (cp)
		i = cp;
	return (i);
}

void			sub_init( struct s_ipcs *ipcs, int nbp)
{
	int		i;

	i = 0;
	while (i < nbp)
	{
		ipcs->semopst[i].sem_num = i;
		ipcs->semopst[i].sem_op = 1;
		ipcs->semopst[i].sem_flg = 0;
		i++;
	}
	semop(ipcs->sem, ipcs->semopst, nbp);
	ipcs->semopst[0].sem_num = i;
	ipcs->semopst[0].sem_op = -1;
}

struct s_shst	*init(key_t k, struct s_shst *info, size_t info_len, \
		int nbp, struct s_ipcs *ipcs)
{
	ipcs->semopst = malloc(sizeof(struct sembuf) * nbp);
	ipcs->shm = shmget(k, info_len, IPC_CREAT | 0666);
	if (ipcs->shm == -1)
	{
		perror("shmget : ");
		exit(1);
	}
	ipcs->sem = semget(k, nbp, IPC_CREAT | 0600);
	if (ipcs->shm == -1)
	{
		perror("semget : ");
		exit(1);
	}
	sub_init(ipcs, nbp);
	semop(ipcs->sem, ipcs->semopst, 1);
	info = shmat(ipcs->shm, NULL, 0);
	if ((int)info < 0)
	{
		perror("shmat : ");
		exit(1);
	}
	return (info);
}
