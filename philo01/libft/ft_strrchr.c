/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:12 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 16:40:07 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)s + idx);
		--idx;
	}
	return (s[idx] == c ? (char *)s + idx : NULL);
}
