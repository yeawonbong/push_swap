#include "push_swap.h"

void    free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void    error_exit(t_stack *stack)
{
	free_all(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void    totop_if(char toswap, t_stack *stack, char stacknum)
{
	int		**st;
	void 	(*swap)(t_stack *stack);

	st = stacknum == 'a' ? &stack->a : &stack->b;
	swap = stacknum == 'a' ? sa : sb;

	if (BIGGER == toswap && (*st)[0] < (*st)[1])
		swap(stack);
	if (SMALLER == toswap && (*st)[0] > (*st)[1])
		swap(stack);
}

void	tobottom_if(char tobottom, t_stack *stack, char stacknum)
{//(더 ~한 수를 swap하고) bottom으로 보내는 축약함수. 
	void 	(*rotate)(t_stack *stack);

	rotate = stacknum == 'a' ? ra : rb;
	totop_if(tobottom, stack, stacknum);
	rotate(stack);
}

int   push_swap(t_stack *stack)
{
	group1_to_stackb(stack);
	group2_to_stackb(stack);


	return 0;
}
