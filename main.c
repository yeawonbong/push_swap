#include "push_swap.h"

int main(int argc, char *argv[])
{
	int i = 1;
	int j = 0;
	char **temp;
	t_list *stack_a;


	while(i < argc)
	{
		printf("%s\n", argv[i]);
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
			printf("j is %d\n", j);
			ft_lstadd_back(&stack_a, ft_lstnew(atoi(temp[j])));
			free(temp[j]);
			j++;
		}
		free(temp);
	}
	printf("content is %d\n", stack_a->content);
printf ("hey\n");
    return 0;
}