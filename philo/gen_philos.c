/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:07 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 16:10:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	gen_philos(t_public *public)
{
	int				i;

	public = call_public();
	public->philo = (t_philo*)malloc(sizeof(t_philo) * public->nop);
	if (!public->philo)
		return (1);
	i = -1;
	while (++i < public->nop)
	{
		public->philo[i].id = i + 1;
		public->philo[i].eat_start = (uint64_t)public->start_time;
		public->philo[i].eat_left = public->number_of_eat;
		public->philo[i].left_fork = public->philo[i].id % public->nop;
		public->philo[i].right_fork = (public->philo[i].id - 1) % public->nop;
		public->philo[i].hands = HANDS_TYPE_EMPTY;
		public->philo[i].eat_start = public->start_time;
	}
	return (0);
}
