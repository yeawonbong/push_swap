/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:43:55 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 04:53:45 by ybong            ###   ########.fr       */
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
			for(int y=0; y < GROUPS; y++)
				printf("피봇이 이상한거니 ? ^^ ,,, %3d\n", stack->pivot[y]);
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
	push_swap(stack);
				printf("^^^^^^^^^^stack a^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->alen); z++)
				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			printf("vvvvvvvvvvstack avvvvvvvv\n\n");

			printf("^^^^^^^^^^stack b^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->blen); z++)
				printf("stack b의 %d번째 숫자: %d\n", z, (stack->b)[z]);
			printf("vvvvvvvvvvstack bvvvvvvvv\n\n");
			printf("0000000000000000000000000\n0000[ COUNT IS : %d ]0000\n0000000000000000000000000\n", stack->count);
	free_all(stack);
	return (0);
}
