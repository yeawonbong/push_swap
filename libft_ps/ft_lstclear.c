/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:55:26 by ybong             #+#    #+#             */
/*   Updated: 2021/06/07 22:12:05 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	if (!lst)
		return ;
	while (ptr)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
}
