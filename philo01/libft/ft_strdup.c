/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:01:38 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 07:41:01 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	len = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
