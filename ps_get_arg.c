#include "push_swap.h"

t_stack	*get_arg(int argc, char *argv[], t_stack *stack)
{
	int				i = 1;
	int 			j = 0;
	char 			**temp=0;
	int 			atoied;

	if (argc < 2)
		return ERROR;
	while(i < argc)
	{
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
printf("IN\n");
printf("temp[j] is %s\n", temp[j]);
			atoied = ft_atoi(temp[j]);
printf("hhhatoied : %d", ft_atoi(temp[j]));
			if (ft_strlen(ft_itoa(atoied)) != ft_strlen(temp[j]))
				return ERROR;
			
			stack->a = add_back(stack->a, atoied);
			free(temp[j]);
			j++;
	 	}
		j = 0;
		free(temp);
	}
	// for(int z = 0; z < (int)(sizeof(stack) / 4); z++)
	// 	printf("stack a의 %d번째 숫자: %d\n", z, stack->a[z]);
	return (stack);
}