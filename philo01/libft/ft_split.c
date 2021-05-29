/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   gend: 2020/10/16 06:45:14 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:45:16 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		while ((*s != '\0') && (*s == c))
			++s;
		if ((*s != '\0') && (*s != c))
			++ret;
		while ((*s != '\0') && (*s != c))
			++s;
	}
	return (ret);
}

static char		*get_next(const char **s, size_t *len_word, char c)
{
	char	*ret;

	while ((**s != '\0') && (**s == c))
		++(*s);
	ret = (char *)*s;
	*len_word = 0;
	while ((**s != '\0') && (**s != c))
	{
		++(*len_word);
		++(*s);
	}
	return (ret);
}

static char		**free_all(char **tab, int k)
{
	int	idx;

	idx = 0;
	while (idx < k)
	{
		free(tab[idx]);
		++idx;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*beg_word;
	size_t	len_word;
	size_t	size;
	size_t	k;

	if (s == NULL)
		return (0);
	size = get_size(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	k = 0;
	beg_word = (char *)s;
	while (k < size)
	{
		beg_word = get_next(&s, &len_word, c);
		if (!(ret[k] = (char *)malloc(sizeof(char) * (len_word + 1))))
			return (free_all(ret, k));
		ft_strlcpy(ret[k], beg_word, len_word + 1);
		++k;
	}
	return (ret);
}
