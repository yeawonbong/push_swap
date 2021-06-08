#include "push_swap.h"

t_list		*get_arg(int argc, char *argv[], t_list *stack)
{
	int				i = 1;
	int 			j = 0;
	char 			**temp;
    int 			atoied;

	if (argc < 2)
		return ERROR;
	while(i < argc)
	{
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
			atoied = ft_atoi(temp[j]);
            if (ft_strlen(ft_itoa(atoied)) != ft_strlen(temp[j]))
                return ERROR;
			ft_lstadd_back(&stack, ft_lstnew(atoied));
			free(temp[j]);
			j++;
		}
		j = 0;
		free(temp);
	}
    stack->size = ft_lstsize(stack);
	return (stack);
}