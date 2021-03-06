/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:05 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 18:15:35 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void
	destroy_mutex(pthread_mutex_t mutex)
{
	int ret;

	ret = pthread_mutex_destroy(&mutex);
	if (ret == EBUSY)
	{
		pthread_mutex_unlock(&mutex);
		ret = pthread_mutex_destroy(&mutex);
	}
}

static void
	destroy_all_mutexs(t_public *public)
{
	int i;

	i = -1;
	while (++i < public->nop)
		destroy_mutex(public->forks[i]);
	destroy_mutex(public->state_mutex);
	destroy_mutex(public->write_mutex);
}

int
	garbage_collector(void)
{
	t_public	*public;

	public = call_public();
	if (public->forks)
	{
		destroy_all_mutexs(public);
		free(public->forks);
	}
	if (public->status)
		free(public->status);
	if (public->philo)
		free(public->philo);
	return (1);
}
