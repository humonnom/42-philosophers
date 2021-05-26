/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:43:54 by yekim             #+#    #+#             */
/*   Updated: 2021/02/10 11:57:29 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*map_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		if (!(map_lst = ft_lstnew((*f)(lst->data))))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, map_lst);
		lst = lst->next;
	}
	return (ret);
}
