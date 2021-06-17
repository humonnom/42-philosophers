/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:07:50 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 16:10:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	act_sleep(t_philo *philo)
{
	t_public	*public;
	int			ret;

	public = call_public();
	ret = display_message(philo, TYPE_SLEEP);
	if (!ret)
		ret = usleep_loop(public->time_to_sleep);
	return (ret);
}
