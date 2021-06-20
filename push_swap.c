#include "push_swap.h"

void    free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted_arr);
	free(stack);
}

void    error_exit(t_stack *stack)
{
	free_all(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void   push_swap(t_stack *stack)
{
	sort_arg(stack, stack->alen);
	duplicates(stack);
	set_pivot(stack);
	if (stack->sortedlen < 10)
		sort_small_args(stack);
	move_to_stackb(stack);

	// 	printf("*********FIN_SORT_IN_STACK B**********\n");
	// printf("TOFIND NOW IS : %d\n", SORTED_BOTTOM);
	sort_stacks(stack, SORTED_BOTTOM, GROUPS - 1);

}

int main(int argc, char *argv[])
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
		printf("PIVOT 3은 뭐길래..... %d\n", stack->pivot[3]);
		printf("PIVOT 4가 뭐길래..... %d\n", stack->pivot[4]);
	free_all(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	// system("leaks a.out");
	return (0);
}
