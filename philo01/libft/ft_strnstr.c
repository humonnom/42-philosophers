/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:09 by yekim             #+#    #+#             */
/*   Updated: 2020/10/11 06:25:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len_haystack;
	size_t	len_needle;
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	count = 0;
	len_haystack = ft_strlen((char *)haystack);
	len_haystack = len_haystack >= n ? n : len_haystack;
	len_needle = ft_strlen((char *)needle);
	if (len_needle > len_haystack)
		return (NULL);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, ft_strlen((char *)needle)))
			return ((char *)haystack);
		if (count >= (len_haystack - len_needle))
			break ;
		++haystack;
		++count;
	}
	return (NULL);
}
