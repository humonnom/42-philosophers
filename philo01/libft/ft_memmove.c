/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:16 by yekim             #+#    #+#             */
/*   Updated: 2020/10/07 08:05:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucsrc;
	unsigned char	*ucdest;
	size_t			idx;

	if (dest == src || n == 0)
		return (dest);
	ucsrc = (unsigned char*)src;
	ucdest = (unsigned char*)dest;
	idx = 0;
	if (dest >= src)
		while (idx++ < n)
			*(ucdest-- + n - 1) = *(ucsrc-- + n - 1);
	else
		while (idx++ < n)
			*(ucdest++) = *(ucsrc++);
	return (dest);
}
