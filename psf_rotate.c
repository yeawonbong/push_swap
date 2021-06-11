/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:55:40 by ybong             #+#    #+#             */
/*   Updated: 2021/06/09 21:28:26 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *stack)
{
	int temp;

	if (stack->alen < 2)
		return ;
	temp = *stack->a;
	stack->a = ft_memmove(stack->a, &stack->a[1], sizeof(int) * (stack->alen - 1));
	stack->a[stack->alen - 1] = temp;
	write(1, "ra\n", 3);
}

void    rb(t_stack *stack)
{
	int temp;

	if (stack->blen < 2)
		return ;
	temp = *stack->b;
	stack->b = ft_memmove(stack->b, &stack->b[1], sizeof(int) * (stack->blen - 1));
	stack->b[stack->blen - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	int temp;

	if (stack->alen < 2 && stack->blen < 2)
		return ;
	if (1 < stack->alen)
	{
		temp = *stack->a;
		stack->a = ft_memmove(stack->a, &stack->a[1], sizeof(int) * (stack->alen - 1));
		stack->a[stack->alen - 1] = temp;
	}
	if (1 < stack->blen)
	{
		temp = *stack->b;
		stack->b = ft_memmove(stack->b, &stack->b[1], sizeof(int) * (stack->blen - 1));
		stack->b[stack->blen - 1] = temp;
	}
	write(1, "rr\n", 3);
}