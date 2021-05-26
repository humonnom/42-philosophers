/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:43:32 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:43:35 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == 0 || del == NULL)
		return ;
	if (*lst == NULL)
		return ;
	ft_lstclear(&((*lst)->next), del);
	del((*lst)->data);
	free(*lst);
	*lst = NULL;
}
