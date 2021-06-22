/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psf_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:24:06 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 19:01:20 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int temp;

	if (stack->alen < 2)
		return ;
	temp = stack->a[stack->alen - 1];
	ft_memmove(&stack->a[1], stack->a, sizeof(int) * (stack->alen - 1));
	*stack->a = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int temp;

	if (stack->blen < 2)
		return ;
	temp = stack->b[stack->blen - 1];
	ft_memmove(&stack->b[1], stack->b, sizeof(int) * (stack->blen - 1));
	*stack->b = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	int temp;

	if (stack->alen < 2 && stack->blen < 2)
		return ;
	if (1 < stack->alen)
	{
		temp = stack->a[stack->alen - 1];
		ft_memmove(&stack->a[1], stack->a, sizeof(int) * (stack->alen - 1));
		*stack->a = temp;
	}
	if (1 < stack->blen)
	{
		temp = stack->b[stack->blen - 1];
		ft_memmove(&stack->b[1], stack->b, sizeof(int) * (stack->blen - 1));
		*stack->b = temp;
	}
	write(1, "rrr\n", 4);
}
