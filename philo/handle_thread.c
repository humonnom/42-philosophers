/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:11 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 18:37:42 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	create_thread_group(t_public *public, int from)
{
	int		ret;
	void	*arg;
	int		i;

	ret = 0;
	i = from;
	while (!ret && i < public->nop)
	{
		arg = &(public->philo[i]);
		ret =\
		pthread_create(&public->philo[i].thread_id, NULL, &philo_routine, arg);
		i += 2;
	}
	return (ret);
}

static int
	handle_one_philo(t_public *public)
{
	if (!usleep_loop(public->time_to_die))
		display_message(public->philo, TYPE_DIED);
	return (0);
}

int
	handle_thread(t_public *public)
{
	int		i;
	int		ret;
	int		status;

	ret = 0;
	if (public->nop == 1)
		ret = handle_one_philo(public);
	if (!ret)
		ret = create_thread_group(public, 0);
	usleep(100);
	if (!ret)
		ret = create_thread_group(public, 1);
	i = -1;
	while (!ret && ++i < public->nop)
		ret = pthread_join(public->philo[i].thread_id, (void **)&status);
	return (ret);
}
