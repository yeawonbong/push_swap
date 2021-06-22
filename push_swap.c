/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:43:55 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 22:10:41 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted_arr);
	free(stack->pivot);
	free(stack);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	push_swap(t_stack *stack)
{
	set_pivot(stack);
	if (stack->sortedlen <= 3) //이럴때 정상종료로 만들어서 익싯 최소화 해보자.
		sort_three(stack);
	else if (stack->sortedlen < 10)
		sort_small_args(stack);
	else
	{
		move_to_stackb(stack);
		sort_stacks(stack, stack->sortedlen - 1, stack->groups - 1);
	}
}

int		main(int argc, char *argv[])
{
	static	t_stack	*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (0);
	get_arg(argc, argv, stack);
	if (150 < stack->sortedlen)
		stack->groups = 15;
	else
		stack->groups = 5;
	duplicates(stack);
	if (cmp_arr(stack))
		push_swap(stack);
	free_all(stack);
	while(1){}
	return (0);
}
