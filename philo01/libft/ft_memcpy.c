/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:13 by yekim             #+#    #+#             */
/*   Updated: 2020/10/07 08:02:27 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ucsrc;
	unsigned char	*ucdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	ucsrc = (unsigned char *)src;
	ucdest = (unsigned char *)dest;
	while (n--)
		*(ucdest++) = *(ucsrc++);
	return (dest);
}
