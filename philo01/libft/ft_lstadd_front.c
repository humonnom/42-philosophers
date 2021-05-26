/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:43:24 by yekim             #+#    #+#             */
/*   Updated: 2021/04/22 14:23:17 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (lst == 0 || new_lst == NULL)
		return ;
	if (*lst != NULL)
		(*lst)->prev = new_lst;
	new_lst->next = *lst;
	*lst = new_lst;
}
