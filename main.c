#include "push_swap.h"

int     main(int argc, char *argv[])
{
	int *p;
	int i = 1;



	t_list	*stack;
	t_list	*head;

	stack = ft_lstnew(2);
//	head = malloc(sizeof(t_list));
	printf("%lu\n", sizeof(int));
	printf("%lu\n", sizeof(head));
	ft_lstadd_back(&stack, ft_lstnew(3));
	//head = ft_lstnew(3);
	//head->next = ft_lstnew(0);
	// ft_lstadd_back(stack, ft_lstnew(p));
	// printf("%d\n",ft_lstsize(*stack));
	return (0);
}
