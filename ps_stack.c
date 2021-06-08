#include "push_swap.h"

int	*add_back(int *stack, int new)
{
	int		*temp;
	size_t	arrlen;

	arrlen = sizeof(stack) / 4;
	if(!stack)
	{
		stack = malloc(sizeof(int));
		*stack = new;
	}
	else
	{
		temp = malloc(sizeof(int) * (arrlen + 1));
		ft_memmove(temp, stack, sizeof(stack));
		temp[arrlen] = new;
	}
	free(stack);
	stack = temp;
	return (stack);
}