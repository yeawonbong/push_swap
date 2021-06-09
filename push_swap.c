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

int   push_swap(t_stack *stack)
{
//    while (A_BOTTOM )
    if (A_BOTTOM < stack->a[0] || A_BOTTOM < stack->a[1])
    {
        if (stack->a[0] < stack->a[1])
            sa(stack);
        pb;//추가
    }
	return 0;
}


