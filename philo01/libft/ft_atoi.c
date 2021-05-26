/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:23:43 by yekim             #+#    #+#             */
/*   Updated: 2020/10/10 07:48:48 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	long long	ret;
	int			sign;

	sign = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			++sign;
		++nptr;
	}
	ret = 0;
	while (ft_isdigit(*nptr))
		ret = ret * 10 + (long long)(*(nptr++) - '0');
	ret = sign % 2 == 0 ? ret : -ret;
	if (ret > LONG_MAX)
		return (-1);
	if (ret < LONG_MIN)
		return (0);
	return ((int)ret);
}
