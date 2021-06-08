#include "push_swap.h"
void    error(t_list *stack_a, t_list *stack_b)
{
    ft_lstclear(&stack_a);
    ft_lstclear(&stack_b);
    write(1, "Error", 5);
}
// int   push_swap(int argc, char *argv[])
// {

// 	return 0;
// }


