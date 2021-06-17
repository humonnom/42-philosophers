/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:48 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 18:09:52 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*watch_died(void *arg)
{
	t_public	*public;
	t_philo		*philo;
	int			eat_left_old;

	philo = (t_philo *)arg;
	public = call_public();
	eat_left_old = philo->eat_left;
	usleep_loop(public->time_to_die);
	if (public->status[philo->id] != TYPE_DONE &&\
							eat_left_old == philo->eat_left)
	{
		public->status[philo->id] = TYPE_DIED;
		pthread_mutex_lock(&public->state_mutex);
		public->state = TYPE_DIED;
		display_message(philo, TYPE_DIED);
		pthread_mutex_unlock(&public->state_mutex);
	}
	return ((void *)0);
}
