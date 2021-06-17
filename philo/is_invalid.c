/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:14 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 16:10:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	is_invalid_argc(int argc)
{
	if (argc == ARG_NUM_WITHOUT_NOE || argc == ARG_NUM_WITH_NOE)
		return (0);
	return (INVALID_ARGC);
}

int
	is_invalid_rule(t_public *public)
{
	if (public->nop < 1)
		return (INVALID_PHILOS_NUM);
	if (public->nop >= 200)
		return (INVALID_PHILOS_NUM);
	if (public->time_to_eat < 60)
		return (INVALID_TIME_SET);
	if (public->time_to_sleep < 60)
		return (INVALID_TIME_SET);
	if (public->time_to_die < 60)
		return (INVALID_TIME_SET);
	if (public->number_of_eat < 0)
		return (INVALID_EAT_NUM);
	return (0);
}
