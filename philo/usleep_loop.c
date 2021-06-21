/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:31 by juepark           #+#    #+#             */
/*   Updated: 2021/06/18 15:25:16 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	usleep_loop(int ms)
{
	t_public	*public;
	u_int64_t	start;
	u_int64_t	end;
	int			ret;

	public = call_public();
	start = get_time();
	end = start + ms;
	ret = 0;
	while (!ret)
	{
		if (get_time() >= end)
			break ;
		if (public->state == TYPE_DIED)
			ret = 1;
		usleep(50);
	}
	return (ret);
}
