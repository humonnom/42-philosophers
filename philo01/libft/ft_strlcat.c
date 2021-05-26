/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:43:57 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 10:29:19 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen((char *)dest);
	len_src = ft_strlen((char *)src);
	if (size <= len_dest)
		return (len_src + size);
	ft_strlcpy(&(dest[len_dest]), src, size - len_dest);
	return (len_src + len_dest);
}
