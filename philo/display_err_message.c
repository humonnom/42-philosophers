/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:07:59 by juepark           #+#    #+#             */
/*   Updated: 2021/06/17 16:10:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	display_err_message(int err_number)
{
	if (err_number == INVALID_ARGC)
		printf("[ Invalid argument number ]\n");
	else if (err_number == INVALID_RULE)
		printf("[ Invalid rule ]\n");
	else if (err_number == INVALID_EAT_NUM)
		printf("[ Invalid eat number ]\n");
	else if (err_number == INVALID_TIME_SET)
		printf("[ Invalid time set(over 60ms) ]\n");
	else if (err_number == INVALID_PHILOS_NUM)
		printf("[ Invalid philos number(correct: 1 ~ 199) ]\n");
	else if (err_number == FAIL_MALLOC)
		printf("[ Malloc failed ]\n");
	else
		printf("[ Undefined error occurred ]\n");
}
