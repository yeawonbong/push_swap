#include "push_swap.h"

t_list		*get_arg(int argc, char *argv[])
{
	char	**temp;
	t_list	*stack_a;
	int 	i;
	int		j;

	if (!argc || *argv)
		return ERROR;
	i = 1;
	j = 0;
	while(i < argc)
	{
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
			ft_lstadd_back(&stack_a, ft_lstnew(temp[j]));
			free(temp[j]);
			j++;
		}
		free(temp);
	}
	stack_a->size = ft_lstsize(stack_a);
	// printf("%d", )
	return (stack_a);
}