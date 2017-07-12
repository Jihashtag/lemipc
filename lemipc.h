/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:01:19 by jbert             #+#    #+#             */
/*   Updated: 2017/02/06 20:41:17 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <stdlib.h>
# include "libftprintf/printf.h"
# include <errno.h>
# include <stdio.h>

int				*get_nearest_ennemy(char *map, int player, int *team);
int				*send_ennemy(int *ennemy, int player, int *t, int cp);
void			get_to_ennemy(int *ennemy, char *map, int player);

# define D 0

# define S 20
# define ID 42

# define NP 1
# define T 0
# define PT 2

# define MSGK 4242

# define SEM struct sembuf

struct			s_ipcs
{
	int			sem;
	int			shm;
	SEM			*semopst;
};

struct			s_msgg
{
	long		mtype;
	int			dist;
	int			pos;
};

# define MSGS sizeof(struct s_msgg)

typedef struct	s_shst
{
	char		map[S * (S + 1) + 1];
	size_t		nbp;
	size_t		cp;
	size_t		rq;
	size_t		rqtype;
	int			ret:2;
	int			t[];
}				t_shst;

void			help(void);
struct s_ipcs	*get_ipcs(struct s_ipcs *ipc);
size_t			get_cp(size_t cp);
void			sub_init(struct s_ipcs *ipcs, int nbp);
t_shst			*init(key_t k, t_shst *in, size_t i, int n, struct s_ipcs *ip);

void			end(struct s_ipcs ipcs, int n);
void			sub_signh(t_shst *info, struct s_ipcs *ipcs, int cp);
void			signal_handler(int sig);
void			put_rand(char c, char *map);
int				nb_team(int *tb, int size);

int				loss(char *map, int me, int *team, int mteam);
void			creator(key_t k, char **av);
void			play_fct(struct s_shst *info, struct s_ipcs ipcs);
t_shst			*play_norm2(t_shst *info, struct s_ipcs ipcs, int i);
t_shst			*play_norm(t_shst *o, struct s_ipcs ipcs, int rq, int rqtype);

int				norm_get_to_ennemy(int *e, char *map, int player, int *mi);
int				*send_ennemy(int *e, int player, int *t, int cp);
void			norm_send_ennemy(struct s_msgg *buf, int *i, int *e);
int				*get_nearest_ennemy(char *map, int player, int *team);
int				found_player(char *map, int *ennemy, int *team, int i);

#endif
