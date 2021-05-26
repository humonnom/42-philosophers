/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:43:04 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:43:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last;

	if (lst == 0 || new_lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_lst;
		return ;
	}
	last = ft_lstlast(*lst);
	new_lst->next = last->next;
	last->next = new_lst;
	new_lst->prev = last;
}
