#include "push_swap.h"
void    free_all(t_stack *stack)
{
    free(stack->a);
    free(stack->b);
    free(stack);
}
// int   push_swap(int argc, char *argv[])
// {

// 	return 0;
// }


