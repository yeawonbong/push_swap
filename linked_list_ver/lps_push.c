#include "push_swap.h"

t_list		*pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	temp = stack_a;
	stack_a = stack_a->next;
	(stack_a->size)--;
	temp->next = stack_b;
	stack_b = temp;
	write(1, "pa\n", 3);
	return (stack_a);
}

// void	pb(t_list *stack_a, t_list *stack_b)
// {
	
// }