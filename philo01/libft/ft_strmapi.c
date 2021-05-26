/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:45:21 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:45:22 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	idx;
	size_t	len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	idx = 0;
	while (s[idx])
	{
		ret[idx] = f(idx, s[idx]);
		++idx;
	}
	return (ret);
}
