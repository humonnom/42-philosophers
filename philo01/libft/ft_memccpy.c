/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:03 by yekim             #+#    #+#             */
/*   Updated: 2020/10/07 08:05:52 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ucsrc;
	unsigned char	*ucdest;
	size_t			idx;

	ucsrc = (unsigned char*)src;
	ucdest = (unsigned char*)dest;
	idx = 0;
	while (idx < n)
	{
		ucdest[idx] = ucsrc[idx];
		if (ucsrc[idx] == (unsigned char)c)
			return (dest + idx + 1);
		++idx;
	}
	return (NULL);
}
