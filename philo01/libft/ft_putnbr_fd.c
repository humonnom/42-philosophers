/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:44:40 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:44:41 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(unsigned int n, int fd)
{
	if (n >= 10)
		print_nbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	int				sign;
	unsigned int	n_tmp;

	if (fd < 0)
		return ;
	sign = n < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar_fd('-', fd);
		n_tmp = -n;
	}
	else
		n_tmp = n;
	print_nbr(n_tmp, fd);
}
