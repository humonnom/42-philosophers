/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:07:46 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 18:10:23 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_public	*public;

	public = call_public();
	philo = (t_philo *)arg;
	while (1)
	{
		if (watch_done(philo))
			return ((void *)1);
		if (act_eat(philo))
			return ((void *)1);
		if (act_sleep(philo))
			return ((void *)1);
		if (act_think(philo))
			return ((void *)1);
	}
	return (0);
}
