/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psf_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:40:01 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 19:01:07 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	temp;

	if (!stack->blen)
		return ;
	temp = *stack->b;
	stack->b = del_front(stack->b, stack->blen);
	stack->a = add_front(stack->a, stack->alen, temp);
	stack->blen--;
	stack->alen++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	int	temp;

	if (!stack->alen)
		return ;
	temp = *stack->a;
	stack->a = del_front(stack->a, stack->alen);
	stack->b = add_front(stack->b, stack->blen, temp);
	stack->alen--;
	stack->blen++;
	write(1, "pb\n", 3);
}
