#include "libft.h"
#include <stdio.h>
int main()
{
	t_list *test;

	// t_list *head=(t_list*)malloc(sizeof(t_list));
	// head->content = intp;
	// printf("%d\n", (head->content));
	test = ft_lstnew(1);
	ft_lstadd_back(&test, ft_lstnew(2));
	
	printf("%d\n", (test->content));
	printf("%d\n", (test->content));
	printf("%d\n", ((test->next)->content));

    return 0;
}