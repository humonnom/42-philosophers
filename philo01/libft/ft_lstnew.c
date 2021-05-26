/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:43:59 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:44:00 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
