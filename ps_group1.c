#include "push_swap.h"

void	group1_to_stackb(t_stack *stack)
{printf("PIVOT IS %d\n", PIVOT);
printf("sortedlen IS %d\n", stack->sortedlen);
	if (stack->a[0] < PIVOT || stack->a[1] < PIVOT) //group1 이라면
		a_to_b_if(BIGGER, stack);
	else
		tobottom_if(SMALLER, stack, 'a'); // 더 작은 수를 to bottom
}