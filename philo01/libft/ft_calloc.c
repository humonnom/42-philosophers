/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:22:51 by yekim             #+#    #+#             */
/*   Updated: 2020/10/07 07:14:59 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	total_size;

	total_size = nmemb * size;
	if (!(ret = malloc(total_size)))
		return (NULL);
	ft_bzero(ret, total_size);
	return (ret);
}
