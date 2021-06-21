/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:43:55 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 20:51:46 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted_arr);
	free(stack);
}

void	error_exit(t_stack *stack)
{
	free_all(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	push_swap(t_stack *stack)
{
	set_pivot(stack);
	if (stack->sortedlen <= 3)
		sort_three(stack);
	else if (stack->sortedlen < 10)
		sort_small_args(stack);
	else
	{
		move_to_stackb(stack);
		sort_stacks(stack, stack->sortedlen - 1, GROUPS - 1);
	}
}

int		main(int argc, char *argv[])
{
	static	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	get_arg(argc, argv, stack);
	duplicates(stack);
	if (cmp_arr(stack))
		push_swap(stack);
	free_all(stack);
	return (0);
}
