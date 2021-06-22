/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psf_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:19:03 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 19:01:33 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int temp;

	if (!stack->a || stack->alen < 2)
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int temp;

	if (!stack->b || stack->blen < 2)
		return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	int temp;

	if ((!stack->a || !stack->a[1]) && (!stack->b || !stack->b[1]))
		return ;
	if (stack->a && stack->a[1])
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	if (stack->b && stack->b[1])
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
	write(1, "ss\n", 3);
}
