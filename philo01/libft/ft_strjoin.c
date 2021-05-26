/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:23:22 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:23:23 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	idx;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = ft_strlcpy(ret, s1, len + 1);
	ft_strlcpy(ret + idx, s2, len + 1);
	return (ret);
}
