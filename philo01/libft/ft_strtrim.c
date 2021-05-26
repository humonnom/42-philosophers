/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:45:24 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:45:25 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_first(const char *s1, const char *tokens)
{
	size_t	len;
	size_t	idx;

	len = ft_strlen(s1);
	idx = 0;
	while (idx < len)
	{
		if (ft_strchr(tokens, s1[idx]) == 0)
			break ;
		idx++;
	}
	return (idx);
}

static int		get_last(const char *s1, const char *tokens)
{
	size_t	len;
	size_t	idx;

	len = ft_strlen(s1);
	idx = 0;
	while (idx < len)
	{
		if (ft_strchr(tokens, s1[len - idx - 1]) == 0)
			break ;
		idx++;
	}
	return (len - idx);
}

char			*ft_strtrim(char const *s1, char const *tokens)
{
	int		first;
	int		last;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	if (tokens == NULL)
		return (ft_strdup(s1));
	first = get_first((char *)s1, tokens);
	last = get_last((char *)s1, tokens);
	if (first >= last)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (last - first + 1))))
		return (NULL);
	ft_strlcpy(ret, s1 + first, last - first + 1);
	return (ret);
}
