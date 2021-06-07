#include "libft.h"
#include <stdio.h>

int main()
{
	int *p;
	int i = 3;

	*p = i;
	printf("p = %d\n", *p);
	t_list *stack;

	stack=ft_lstnew(p=&6);
	printf("%d\n", *(int*)(stack->content));
	// printf("test: %d\n", *(int*)((ft_lstnew(&i))->content));
	return (0);
}