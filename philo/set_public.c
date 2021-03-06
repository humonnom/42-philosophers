/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_public.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:29 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 18:39:50 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	set_forks_info(t_public *public)
{
	int	i;
	int	ret;

	public->forks =\
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * public->nop);
	public->status = (int *)malloc(sizeof(int) * public->nop + 1);
	if (!public->forks || !public->status)
		return (1);
	ret = 0;
	i = -1;
	while (!ret && ++i < public->nop)
		ret = pthread_mutex_init(&public->forks[i], NULL);
	i = 0;
	while (!ret && ++i < public->nop + 1)
		public->status[i] = TYPE_INIT;
	return (ret);
}

static int
	init_mutexs(t_public *public)
{
	int ret;

	ret = pthread_mutex_init(&public->write_mutex, NULL);
	if (!ret)
		ret = pthread_mutex_init(&public->state_mutex, NULL);
	return (ret);
}

int
	set_public(
					t_public *public,
					char **public_str,
					int arg_num)
{
	public->nop = ft_atoi(public_str[0]);
	public->time_to_die = (uint64_t)ft_atoi(public_str[1]);
	public->time_to_eat = (uint64_t)ft_atoi(public_str[2]);
	public->time_to_sleep = (uint64_t)ft_atoi(public_str[3]);
	if (arg_num == ARG_NUM_WITH_NOE)
		public->number_of_eat = ft_atoi(public_str[4]);
	else
		public->number_of_eat = UNDECIDED_NOE;
	if (is_invalid_rule(public))
		return (INVALID_RULE);
	public->start_time = get_time();
	public->state = TYPE_INIT;
	public->print_flag = TYPE_PRINT_VALID;
	if (set_forks_info(public))
		return (FAIL_MALLOC);
	if (init_mutexs(public))
		return (FAIL_MALLOC);
	return (0);
}
