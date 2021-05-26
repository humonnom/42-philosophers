/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:45:10 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:45:11 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	handle_nbr(unsigned int n, char *n_buf, int k, int flag)
{
	size_t	ret;
	int		mod;

	ret = 1;
	if (n >= 10)
		ret += handle_nbr(n / 10, n_buf, k - 1, flag);
	if (flag)
	{
		mod = n % 10;
		n_buf[k] = (char)(mod + '0');
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	unsigned int	tmp_n;
	size_t			len_ret;
	char			*ret;

	tmp_n = n < 0 ? -n : n;
	len_ret = handle_nbr(tmp_n, NULL, 0, 0);
	len_ret = n < 0 ? len_ret + 1 : len_ret;
	if (!(ret = (char *)malloc(sizeof(char) * (len_ret + 1))))
		return (NULL);
	ret[len_ret] = '\0';
	handle_nbr(tmp_n, ret, (int)len_ret - 1, 1);
	ret[0] = n < 0 ? '-' : ret[0];
	return (ret);
}
